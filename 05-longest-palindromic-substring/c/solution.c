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
    TESTCASE = ""eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee""
    

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delimitString(char *s, char *delim_s)
{
    // 'babad' --> :this: --> '|b|a|b|a|d|'

    long size = strlen(s);
    const char delim = '|';

    long i = 0, j = 0;
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
    
    long size = strlen(s);                   // the size of a string
    long sizePlus = size * 2 + 1;            // the size of delimited string in case it is even, e. g. (abba) the center would be |a|b *|* b|a
    
    long max_substr_size = 0;                // max value of substr (to find the longest)
    char *result = (char*)malloc(sizeof(char) * (sizePlus + 1));

    char *superstr = (char*)malloc(sizeof(char) * (sizePlus + 1));
    superstr = delimitString(s, superstr);

    long i = 0;
    while (i < sizePlus)
    {
        long center = i;
        long left = center;
        long right = center;

        if (i == 0) {
            while (right < sizePlus) {
                if (superstr[center] == superstr[right]) {
                    // printf("%l:LB1:W1:LB1: %c\t", i, superstr[right]);
                    right += 1;
                } else break;
            }
        } 
        else if (i == (sizePlus - 1)) {
            while (left > 0) {
                if (superstr[center] == superstr[left]) {
                    // printf("%l:LB2:W1:LB1: %c\t", i, superstr[left]);
                    left -= 1;
                } else break;
            }
        }
        else {

            left = center - 1;
            right = center + 1;
            
            long substr_size = superstr[center] == '|' ? 0: 1;

            while ((left > 0) && (right < sizePlus)) {
                if (superstr[left] == superstr[right]) {

                    if (superstr[left] != '|') {
                        substr_size += 2;
                        // printf("%l:LB3:W1:LB1: %c%c\t", i, superstr[left], superstr[right]);

                    }
                
                    right += 1;
                    left -= 1;
                } else {
                    break;
                }
            }
            if (substr_size > max_substr_size) {
                max_substr_size = substr_size;
                

                result = realloc(result, sizeof(char) * (max_substr_size + 1));

                long j = left + 1;
                long k = 0;
                while (1) {
                    if (superstr[j] == '|') {
                        j++;
                        continue;
                    }
                    if (k == max_substr_size) {
                        result[k] = '\0';
                        break;
                    }
                    result[k] = superstr[j];
                    k++;
                    j++;
                }

            }
        }

        i++;
    }
    

    // printf("max_substr_size: %l\n", max_substr_size);
    // printf("result: %s\n", result);
    // printf("superstring: %s\n", superstr);
    free(superstr);
    return result;
}

int main(int argc, char *argv[])
{
    // char *testCase = "a";
    // char *testCase = "ac";
    // char *testCase = "ccbca";
    // char *testCase = "aab";
    // char *testCase = "cbbd";
    // char *testCase = "babad";
    // char *testCase = "tacocat";
    // char *testCase = "aacabdkacaa";
    char *testCase = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    
    char *result = longestPalindrome(testCase);

    printf("\nresult: %s\n", result);

    return 0;
}