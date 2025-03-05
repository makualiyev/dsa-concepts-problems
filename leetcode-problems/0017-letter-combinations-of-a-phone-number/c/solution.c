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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char** resultArr = malloc(sizeof(char *) * 1);
    resultArr[0] = malloc(sizeof(char) * 3);
    resultArr[0] = strcpy(resultArr[0], "");

    char* tempPtr = digits;
    int count = 0;
    while (*tempPtr != '\0') {
        *tempPtr++;
        count++;
    }
    printf("count:%d\n", count);

    int i = 0;
    while (digits[i] != '\0') {
        int tempDigit = (int)digits[i] - 48;
        char* tempDigitRepr = find_symbol(tempDigit)->name;
        printf("DEBUG\ttempDigit:%d\ttempDigitRepr:%s\n", tempDigit, tempDigitRepr);
        i++;
    }

    *returnSize = 1;
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


    char* digits = "2";
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

    free(result[0]);
    free(result);

    return 0;
}
