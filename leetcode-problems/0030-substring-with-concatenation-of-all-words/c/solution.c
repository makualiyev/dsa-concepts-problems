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
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"


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
struct hash_entry *result_entries = NULL;

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
        s->id = s->id + entry_id;
    }
}

void add_result_entry(int entry_id, const char *name)
{
    struct hash_entry *s;

    HASH_FIND_STR(result_entries, name, s);    /* id already in the hash? */
    if (s == NULL) {
        s = (struct hash_entry*)malloc(sizeof *s);
        s->name = malloc(sizeof(char) * (strlen(name) + 1));
        s->name = strncpy(s->name, name, strlen(name) + 1);
        s->id = entry_id;
        HASH_ADD_STR(result_entries, name, s); /* 'name' here refers to the struct field */
    } else {
        s->id = s->id + entry_id;
    }
}

struct hash_entry *find_entry(const char *name)
{
    struct hash_entry *found_entry;
    HASH_FIND_STR(entries, name, found_entry);
    return found_entry;
}

struct hash_entry *find_result_entry(const char *name)
{
    struct hash_entry *found_entry;
    HASH_FIND_STR(result_entries, name, found_entry);
    return found_entry;
}

void delete_entries(void)
{
    struct hash_entry *current_entry, *tmp;
    HASH_ITER(hh, entries, current_entry, tmp) {
        HASH_DEL(entries, current_entry);
        free(current_entry->name);
        free(current_entry);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * @param wordsSize - size of an array containing words to be concatenated
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int *result = NULL;
    *returnSize = 0;
    int sLen = (int)strlen(s);
    int wLen = (int)strlen(words[0]);

    for (int wI = 0; wI < wordsSize; wI++) {
        add_entry(wI + 1, words[wI]);
    }
    
	int i = 0;
    int fI = 0;
	while (1)
	{
        if ((wLen * wordsSize + i) > sLen) break;
        
        /* First loop for a window size */
		for (int j = i; j < (wLen * wordsSize + i); j = j + wLen) {             /* buffer for each word in the window*/
            char *sName = (char *)malloc(sizeof(char) * (size_t)(wLen + 1));
            for (int k = j, m = 0; k < (wLen + j); k++, m++) {                  /* Second loop for each word in the window */
                sName[m] = s[k];
            }
            sName[wLen] = '\0';
            if (find_entry(sName)) {
                add_result_entry(1, sName);
            }
            free(sName);
		}
        
		/* Main logic ? */
        int checkLogic = 0;
        for (int wI = 0; wI < wordsSize; wI++) {
            if (find_result_entry(words[wI]) && find_entry(words[wI])->id == find_result_entry(words[wI])->id) {
                checkLogic++;
            }
        }
        if (checkLogic == wordsSize) {
            *returnSize += 1;
            result = (int *)realloc(result, sizeof(int) * (size_t)(*returnSize));
            result[fI] = i;
            fI++;
        }
        
		i++;
	}

    return result;
}
