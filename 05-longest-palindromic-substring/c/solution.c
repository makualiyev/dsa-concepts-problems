/*
    -------------------------
    Topics:
    * Two Pointers
    * String
    * Dynamic Programming

    -------------------------
    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

    -------------------------
    Testcases:

    TESTCASE = "babad"              // "bab"     | Explanation: "aba" is also a valid answer.
    TESTCASE = "cbbd"               // "bb"      |
    TESTCASE = "ac"                 // "a"       |
    TESTCASE = "abb"                // "bb"      |
    TESTCASE = "tacocat"            // "tacocat" |
    TESTCASE = "aacabdkacaa"        // "aca"     | 
    
    

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *delimitString(char *s, char *delim_s)
{
    int size = strlen(s);
    const char delim = '|';

    int i = 0, j = 0;
    while (i < (size * 2 + 2))
    {
        if (i == (size * 2 + 1))
        {
            delim_s[i] = '\0';
            break;
        }

        if (i % 2 == 0)
        {
            delim_s[i] = delim;
        }
        else
        {
            delim_s[i] = s[j];
            j++;
        }
        i++;
    }
    return delim_s;
    
}
char *longestPalindrome(char *s)
{
    //  b  a  b  a  b  a  d
    // '|  b  |  a  |  b  |  a  |  d  |'
    //  0  1  2  3  4  5  6  7  8  9  10
    //  *  0  *  1  *  2  *  4  *  5  *
    
    int size = strlen(s);                   // the size of a string
    int sizePlus = size * 2 + 1;            // the size of delimited string in case it is even, e. g. (abba) the center would be |a|b *|* b|a 
    int isEven = (size % 2) ? 0 : 1;         // check if odd
    const char delim = '|';                 // delimiter
    int max_substr_size = 0;                // max value of substr (to find the longest)
    
    char *result = (char*)malloc(sizeof(char) * (sizePlus + 1));
    
    
    if (size == 1) {
        strncpy(result, s, sizeof(char) * (size + 1));
        return result;
    }

    if (size == 2) {
        if (s[0] == s[1]) {
            strncpy(result, s, sizeof(char) * (size + 1));
            return result;
        }
        result = (char *)realloc(result, sizeof(char) * 2);
        for (int i = 0; i < 2; i++) {
            result[i] = s[i];
            if (i == 1) {
                result[i] = '\0';
                break;
            }
        }
        return result;
        
    }
    
    // filling the original string with delimiters '|' and then we get 'superstring'
    char *superstr = (char*)malloc(sizeof(char) * (sizePlus + 1));

    if (isEven) {
        superstr = delimitString(s, superstr);
    } else {
        superstr = (char*)realloc(superstr, sizeof(char) * (size + 1));
        strncpy(superstr, s, sizeof(char) * (size + 1));
    }

    
    printf("size of string: %d\n", size);
    printf("superstring: %s\n", superstr);

    free(superstr);
    return result;
}

int main(int argc, char *argv[])
{
    // char *testCase = "aacabdkacaa";
    // char *testCase = "babad";
    char *testCase = "cbbd";
    // char *testCase = "ac";
    // char *testCase = "abb";
    // char *testCase = "tacocat";
    
    char *result = longestPalindrome(testCase);

    printf("result: %s\n", result);

    return 0;
}