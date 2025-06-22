/*
    Given a string containing digits from 2-9 inclusive, return all possible
    letter combinations that the number could represent. Return the answer
    in any order.

    A mapping of digits to letters (just like on the telephone buttons) is
    given below. Note that 1 does not map to any letters.
    -------------------------
    Topics:
    * Hash Table
    * String
    * Backtracking
    -------------------------
    Constraints:
    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
    -------------------------
    Testcases:
    Input: digits = "23"                    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Input: digits = ""                      // Output: []
    Input: digits = "2"                     // Output: ["a","b","c"]
    
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "uthash.h"

struct hash_entry {
    int id;             /* we'll use this field as a key */
    char name[10];
    UT_hash_handle hh;  /* makes this structure hashable */
};

struct hash_entry *symbols = NULL;

void add_symbol(int symbol_id, const char *name)
{
    struct hash_entry *s;

    HASH_FIND_INT(symbols, &symbol_id, s);  /* id already in the hash? */
    if (s == NULL) {
        s = (struct hash_entry*)malloc(sizeof *s);
        s->id = symbol_id;
        HASH_ADD_INT(symbols, id, s);  /* id is the key field */
    }
    strcpy(s->name, name);
}

struct hash_entry *find_symbol(int symbol_id)
{
    struct hash_entry *s;

    HASH_FIND_INT(symbols, &symbol_id, s);  /* s: output pointer */
    return s;
}

void print_symbols(void)
{
    struct hash_entry *s;

    for (s = symbols; s != NULL; s = (struct hash_entry*)(s->hh.next)) {
        printf("symbol id %d: name %s\n", s->id, s->name);
    }
}

void printCharArr(char **charArr, int *arrSize)
{
    for (int i = 0; i < *arrSize; i++) {
        int j = 0;
        while (charArr[i][j] != '\0') {
            printf("%c", charArr[i][j]);
            j++;
        }
        printf("\t");
    }
    printf("\n");
}

void multiplyLetters(char** resultArr, int* totalCount, char* digitsLetters)
{
    if (*totalCount == 0) {
        for (int i = 0; i < (int)strlen(digitsLetters); i++) {
            resultArr[*totalCount] = (char *)malloc(sizeof(char) * 2);
            resultArr[*totalCount][0] = digitsLetters[i];
            resultArr[*totalCount][1] = '\0';
            *totalCount = *totalCount + 1;
        }
        return;
    }
    char** tempResArr = (char **)malloc(sizeof(char *) * ((size_t)(*totalCount) * strlen(digitsLetters)));
    int tempTotalCount = 0;

    for (int i = 0; i < *totalCount; i++) {
        for (int j = 0; j < (int)strlen(digitsLetters); j++) {
            int tempLetterLen = (int)strlen(resultArr[i]);
            tempResArr[tempTotalCount] = (char *)malloc(sizeof(char) * ((size_t)tempLetterLen + 2));
            tempResArr[tempTotalCount] = strcpy(tempResArr[tempTotalCount], resultArr[i]);
            tempResArr[tempTotalCount][tempLetterLen] = digitsLetters[j];
            tempResArr[tempTotalCount][tempLetterLen + 1] = '\0';
            tempTotalCount++;
        }
    }

    // freeing previous values in the result array
    for (int idx = 0; idx < *totalCount; idx++) {
        free(resultArr[idx]);
    }

    for (int idx = 0; idx < tempTotalCount; idx++) {
        resultArr[idx] = tempResArr[idx];
    }

    free(tempResArr);
    *totalCount = tempTotalCount;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
    /**
     * Filling up the array with corresponding letters using
     * hash table. We are also counting up how many possible
     * combinations we have with given digits by saving it to
     * `maxPossibleCombos`
     */
    int digitsCount = (int)strlen(digits);
    char** digitsLetters = (char **)malloc(sizeof(char *) * (size_t)digitsCount);
    int i = 0;
    int maxPossibleCombos = 1;

    while (digits[i] != '\0') {
        int tempDigit = (int)digits[i] - 48;
        char *tempDigitRepr = find_symbol(tempDigit)->name;
        maxPossibleCombos = maxPossibleCombos * (int)strlen(tempDigitRepr);
        digitsLetters[i] = tempDigitRepr;
        i++;
    }

    printf("DEBUG\tmaxPossibleCombos:%d\n", maxPossibleCombos);

    /**
     * Creating the result array and allocating it with `maxPossibleCombos`
     * char pointers.
     */
    char** resultArr = (char **)malloc(sizeof(char *) * (size_t)maxPossibleCombos);
    int totalCount = 0;

    /**
     * Main logic
     * 2 x 3 = (a + b + c) x (d + e + f) = ad + ae + af + bd + be + bf + cd + ce + cf
     * (a + b) x (d + e) x (g + h) = (ad + ae + bd + be) x (g + h) = adg + adh + aeg + aeh + bdg + bdh + beg + beh
     * (a + b + c) = a + b + c
     */

    if (digitsCount > 0) {
        for (int idx = 0; idx < digitsCount; idx++) {
            multiplyLetters(resultArr, &totalCount, digitsLetters[idx]);
        }
    }

    *returnSize = totalCount;
    free(digitsLetters);
    return resultArr;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");

    add_symbol(2, "abc");
    add_symbol(3, "def");
    add_symbol(4, "ghi");
    add_symbol(5, "jkl");
    add_symbol(6, "mno");
    add_symbol(7, "pqrs");
    add_symbol(8, "tuv");
    add_symbol(9, "wxyz");


    char* digits = "23";
    int returnSize = 0;

    clock_t start = clock();
    char** result = letterCombinations(digits, &returnSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: %s\n", digits);
    printf("result:\t");
    printCharArr(result, &returnSize);
    printf("\nTime elapsed: %.4f\n", seconds);

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
