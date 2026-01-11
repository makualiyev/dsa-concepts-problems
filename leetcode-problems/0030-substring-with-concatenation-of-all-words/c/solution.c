/*
    -------------------------
    Topics:
    * Hash Table
    * String
    * Sliding Window
    -------------------------
    Constraints:
    * 1 <= s.length <= 10^4
    * 1 <= words.length <= 5000
    * 1 <= words[i].length <= 30
    * s and words[i] consist of lowercase English letters.
    -------------------------
    Testcases:
    Input: s = "barfoothefoobarman", words = ["foo","bar"]                          // Output: [0, 9]
    Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]    // Output: []
    Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]              // Output: [6,9,12]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../../templates/include/uthash.h"

void printIntArr(int *intArr, int *intArrSize)
{
    printf("[");
    for (int i = 0; i < *intArrSize; i++) {
        printf("%d%s", intArr[i], (i == *intArrSize - 1) ? "": ",");
    }
    printf("]\n");
}

void printStringArr(char **words, int wordsSize)
{
    printf("[");
    for (int i = 0; i < wordsSize; i++) {
        printf("%s%s", words[i], (i == wordsSize - 1) ? "": ",");
    }
    printf("]\n");
}

struct hash_entry {
    char *name;
    int id;             /* we'll use this field as a key */
    UT_hash_handle hh;  /* makes this structure hashable */
};

struct hash_entry *entries = NULL;

void add_entry(int entry_id, const char *name)
{
    struct hash_entry *s;

    HASH_FIND_STR(entries, name, s);    /* id already in the hash? */
    if (s == NULL) {
        s = (struct hash_entry*)malloc(sizeof *s);
        s->name = malloc(sizeof(char) * (strlen(name) + 1));
        s->name = strncpy(s->name, name, strlen(name) + 1);
        s->id = entry_id;
        HASH_ADD_STR(entries, name, s); /* 'name' here refers to the struct field */
    } else {
        s->id = entry_id;
    }
}

struct hash_entry *find_entry(const char *name)
{
    struct hash_entry *found_entry;
    HASH_FIND_STR(entries, name, found_entry);
    return found_entry;
}

// void delete_entries(void)
// {
//     struct hash_entry *current_entry, *tmp;
//     HASH_ITER()
// }

void print_entries(void)
{
    struct hash_entry *s;

    for (s = entries; s != NULL; s = (struct hash_entry*)(s->hh.next)) {
        printf("entry id %d: name %s\n", s->id, s->name);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * @param wordsSize - size of an array containing words to be concatenated
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int *result = NULL;
    *returnSize = 0;
    char buffer[100];
    int sLen = (int)strlen(s);
    int wLen = (int)strlen(words[0]);
    int wSumCheck = 0;

    for (int wI = 0; wI < wordsSize; wI++) {
        add_entry(wI + 1, words[wI]);
        wSumCheck += (wI + 1);
    }
    print_entries();
    printf("wSumCheck:%d\n\n", wSumCheck);
    
	int i = 0;
    int fI = 0;
	while (1)
	{
        if ((wLen * wordsSize + i) > sLen) break;
        int sumCum = 0;
        
        /* First loop for a window size */
		for (int j = i; j < (wLen * wordsSize + i); j = j + wLen) {
            
            /* buffer for each word in the window*/
            char *sName = (char *)malloc(sizeof(char) * (size_t)(wLen + 1));
            /* Second loop for each word in the window */
            for (int k = j, m = 0; k < (wLen + j); k++, m++) {
                printf("%c", s[k]);
                sName[m] = s[k];
            }
            sName[wLen] = '\0';
            
            if (find_entry(sName)) {
                sumCum += find_entry(sName)->id;
            }
            free(sName);
            printf("\t");

		}
        if (sumCum == wSumCheck) {
            printf("\nFOUND i=%d\n", i);
            *returnSize += 1;
            result = (int *)realloc(result, sizeof(int) * (size_t)(*returnSize));
            result[fI] = i;
            fI++;
        }
        printf("\n");
		
		i = i + wLen;
	}

    return result;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    // Output: [6,9,12]
    char *s = "wordgoodgoodgoodbestword";
    int wordsSize = 4;
    char *words[] = {"word","good","best","word"};
    int returnSize = 0;
    
    clock_t start = clock();
    
    printf("======================\n");
    printf("testCase: \n");
    printf("\tstring:%s\n\twords:", s);
    printStringArr(words, wordsSize);

    int *result = findSubstring(s, words, wordsSize, &returnSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    
    printf("======================\n");
    printf("result:\n\t");
	if (returnSize != 0) {
    	printIntArr(result, &returnSize);
	}

    printf("\nTime elapsed: %.4f\n", seconds);
    free(result);
    return 0;
}
