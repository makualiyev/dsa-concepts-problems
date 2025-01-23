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
    Input: s = "aa", p = "a"                                        // Output: false
    Input: s = "aa", p = "a*"                                       // Output: true
    Input: s = "ab", p = ".*"                                       // Output: true
    Input: s = "aab", p = "c*a*b"                                   // Output: true
    Input: s = "mississippi", p = "mis*is*ip*."                     // Output: true
    Input: s = "ab", p = ".*c"                                      // Output: false
    Input: s = "aaa", p = "aaaa"                                    // Output: false
    Input: s = "a", p = "ab*"                                       // Output: true
    Input: s = "a", p = ".*..a*"                                    // Output: false
    Input: s = "aab", p = "c*a*b"                                   // Output: true
    Input: s = "aaa", p = "ab*ac*a"                                 // Output: true
    Input: s = "aaa", p = "ab*a*c*a"                                // Output: true
    Input: s = "aaa", p = "aaaa"                                    // Output: false
    Input: s = "a",   p = "ab*a"                                    // Output: false
    Input: s = "abcdede", p = "ab.*de"                              // Output: true
    Input: s = "aaa", p = "a*a"                                     // Output: true
    Input: s = "aabcbcbcaccbcaabc", p = ".*a*aa*.*b*.c*.*a*"        // Output: true
    Input: s = "aaca", p = "ab*a*c*a"                               // Output: true
    Input: s = "bbbba", p = ".*a*a"                                 // Output: true

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool matchPattern(char *s, char *p)
{
    int i = 0;
    int j = 0;

    while (i < (int)strlen(s)) {
        printf("i:%d\tc:%c\n", i, s[i]);
        if (j < (int)strlen(p)) {
            if (s[i] != p[j]) {
                return false;
            }
            j++;
        }
        i++;
    }
    if (j < (int)strlen(p)) return false;
    return true;
}

bool isMatch(char *s, char *p)
{
    bool result = matchPattern(s, p);
    return result;
}

int main(int argc, char *argv[])
{
    char *testCaseS = "aaaa";
    char *testCaseP = "aaa";
    // Output: true

    bool result = isMatch(testCaseS, testCaseP);

    printf("\n======================\n");
    printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    return 0;
}
