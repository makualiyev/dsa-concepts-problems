/*
    Seven different symbols represent Roman numerals with the following values:
    Symbol	Value
    I       1
    V	    5
    X	    10
    L	    50
    C	    100
    D	    500
    M	    1000
    Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral
    has the following rules:

    *   If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result,
    subtract its value, and convert the remainder to a Roman numeral.
    *   If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than
    5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
    *   Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D)
    multiple times. If you need to append a symbol 4 times use the subtractive form.

    Given an integer, convert it to a Roman numeral.

    -------------------------
    Topics:
    * Hash Table
    * Math
    * String
    -------------------------
    Constraints:
    1 <= num <= 3999
    -------------------------
    Testcases:
    Input: num = 3749                               // Output: "MMMDCCXLIX"
        Explanation:
        3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
         700 = DCC as 500 (D) + 100 (C) + 100 (C)
           40 = XL as 10 (X) less of 50 (L)
              9 = IX as 1 (I) less of 10 (X)

        Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

    Input: num = 58                                 // Output: "LVIII"
        Explanation:
        50 = L
         8 = VIII

    Input: num = 1994                               // Output: "MCMXCIV"
        Explanation:
        1000 = M
         900 = CM
           90 = XC
              4 = IV
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

char* intToRomanPowerOne(int num) {
    /* 1    2    3  4   5   6   7   8       9 */
    /* I    II  III IV  V   VI  VII VIII    IX*/
    /*                  V                     */

    char* res = (char *)malloc(sizeof(char) * 1024);
    // res = strcpy(res, "");
    res = strcpy(res, find_symbol(10)->name);
    return res;

}

char* intToRoman(int num) {
    char *result = (char *)malloc(sizeof(char) * 1024);
    result = strcpy(result, "");

    int i = 0;
    while (1) {
        int powerNum = (int)pow((double)10, (double)i) * (num % 10);
        int digit = (int)(num % 10);
        int powerOfTen = i;

        printf("i:%d\t", i);
        printf("mod:%d\t", num % 10);
        printf("rem:%d\t", num / 10);
        printf("power:%d\t", powerNum);
        
        printf("mod%%5: %d\t", (num % 10) % 5);
        printf("mod/5: %d\n", (num % 10) / 5);

        // if decimal place modulo 5 equals 4
        // then it is a subtraction form 
        if (digit % 5 == 4) {
            if (digit / 5 == 1) {
                result = strcat(result, find_symbol((int)pow((double)10, (double)powerOfTen))->name);
                result = strcat(result, find_symbol((int)pow((double)10, (double)(powerOfTen + 1)))->name);
            } else {
                result = strcat(result, find_symbol((int)pow((double)10, (double)powerOfTen))->name);
                result = strcat(result, find_symbol(5 * (int)pow((double)10, (double)powerOfTen))->name);
            }
        } else if ((digit % 5 == 0) && (i != 0)) {
            result = strcat(result, find_symbol((int)pow((double)10, (double)powerOfTen) * digit)->name);
        }

        num = num / 10;
        if (!num)
            break;
        i++;
    }

    return result;
}

int main(int argc, char *argv[])
{
    int num = 450;
    // int num = 11;
    // LVIII
    add_symbol(1, "I");
    add_symbol(5, "V");
    add_symbol(10, "X");
    add_symbol(50, "L");
    add_symbol(100, "C");
    add_symbol(500, "D");
    add_symbol(1000, "M");

    char* result = intToRoman(num);
    // char* result = intToRomanPowerOne(num);

    printf("======================\n");
    printf("testCase: %d\nresult:\t%s\n", num, result);
    free(result);
    return 0;
}
