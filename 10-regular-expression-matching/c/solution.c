/*
    Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).

    -------------------------
    Topics:
    * String
    * Dynamic Programming
    * Recursion
    -------------------------
    Constraints:
    1 <= s.length <= 20
    1 <= p.length <= 20
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
    -------------------------
    Testcases:
    Input: s = "aa", p = "a"                        // Output: false
    Input: s = "aa", p = "a*"                       // Output: true
    Input: s = "ab", p = ".*"                       // Output: false
    Input: s = "aab", p = "c*a*b"                   // Output: true
    Input: s = "mississippi", p = "mis*is*ip*."     // Output: true
    Input: s = "ab", p = ".*c"                      // Output: false
    Input: s = "aaa", p = "aaaa"                    // Output: false
    Input: s = "a", p = "ab*"                       // Output: true
    Input: s = "a", p = ".*..a*"                    // Output: false
    Input: s = "aab", p = "c*a*b"                   // Output: true
    Input: s = "aaa", p = "ab*a*c*a"                // Output: true

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int patternMatch(int caret, char *s, char pattern, int isAsterisk, int *simpleCheck)
{
    int i = caret;

    if (isAsterisk)
    {
        
        while (i >= 0)
        {
            if (pattern == '.') {
                i--;
                continue;
            }
            if (s[i] == pattern)
            {
                i--;
                continue;
            }
            break;
        }
    }
    else
    {
        if (pattern == '.') {
            i--;
            return i;
        }
        else if (s[i] == pattern)
        {
            i--;
            return i;
        } else {
            *simpleCheck = 1;
        }
    }
    return i;
}

bool isMatch(char *s, char *p)
{
    int asteriskCount = 0;
    int simpleCount = 0;
    int patternLen = (int)strlen(p);
    int caret = (int)strlen(s) - 1;
    int simpleCheck = 0;                // true if simple pattern matching fails

    for (int i = patternLen - 1, j = patternLen - 2; i >= 0; i -= 1, j = i - 1)
    {
        printf("\tloop started -> i:%d, caret:%d\n", i, caret);   
        if (caret < 0)
        {
            printf("\tcaret ended\n");
            if (p[i] == '*')
            {
                asteriskCount++;
            }
            break;
        }
        if (j < 0)
        {
            simpleCount++;
            caret = patternMatch(caret, s, p[i], 0, &simpleCheck);
            printf("\tloop breaks -> i:%d, caret:%d, simpleCheck:%d\n", i, caret, simpleCheck);
            break;
        }
        if (p[i] == '*')
        {
            printf("\t\tfound pattern -> i:%d, j:%d, pattern:%c, simpleCheck:%d\n", i, j, p[j], simpleCheck);
            asteriskCount++;
            if (i == j) {
                caret = patternMatch(caret, s, p[j - 1], 1, &simpleCheck);
            } else {
                caret = patternMatch(caret, s, p[j], 1, &simpleCheck);
            }

            if (j == (patternLen - 1)) {
                i = j - 1;
            } else {
                i = j;
            }
            
            printf("\t\t end found pattern -> i:%d, caret:%d, simpleCheck:%d\n", i, caret, simpleCheck);
        }
        else
        {
            simpleCount++;
            caret = patternMatch(caret, s, p[i], 0, &simpleCheck);
            printf("\t\tfound nonpattern -> i:%d, caret:%d, simpleCheck:%d\n", i, caret, simpleCheck);
        }
    }

    printf("\n(asteriskCount + simpleCount):%d\n", (asteriskCount * 2 + simpleCount));


    if ((asteriskCount * 2 + simpleCount) < strlen(p)) {
        return false;
    }

    if ((asteriskCount == 0) && (strlen(p) > strlen(s)))
    {
        return false;
    }

    if (simpleCheck)
    {
        return false;
    }
    
    if (caret >= 0) {
        return false;
    } else {
        return true;
    }
}

int main(int argc, char *argv[])
{
    // char *testCaseS = "mississippi";
    // char *testCaseP = "mis*is*ip*.";
    // char *testCaseS = "aa";
    // char *testCaseP = "a*";
    // char *testCaseS = "a";
    // char *testCaseP = ".*..a*";

    char *testCaseS = "aaa";
    char *testCaseP = "ab*a*c*a";

    bool result = isMatch(testCaseS, testCaseP);

    printf("======================\n");
    printf("\ntestCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    return 0;
}
