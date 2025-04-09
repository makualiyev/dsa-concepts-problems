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
#include <time.h>

bool isMatch(char *s, char *p)
{
    int slen = (int)strlen(s), plen = (int)strlen(p);
    int isMatch = 1;
    int i = 0, j = 0;
    
    while (i < slen)
    {
        if (j >= plen) {
            isMatch = false;
            break;
        }
        if (j < (plen - 1) && p[j + 1] == '*') {
            if (s[i] != p[j] && p[j] != '.') {
                j = j + 2;
                continue;
            } else {
                i = i + 1;
                continue;
            }
        }
        if (s[i] != p[j] && p[j] != '.') {
            isMatch = false;
            break;
        }
        i++;
        j++;
    }
    if (j < plen && p[plen - 1] != '*') {
        isMatch = false;
    }
    return isMatch;
}

void runTestCase(char* s, char* p, int output)
{
    bool result = isMatch(s, p);
    printf(
        "%s\tInput: s = \"%s\", p = \"%s\"\tExpected: %s\n",
        (result == output? "PASS": "FAIL"),
        s, p, (output? "true": "false")
    );
}

void runAllTestCases(void)
{
    // runTestCase("aa", "a", false);
    // runTestCase("a", "aa", false);
    // runTestCase("abc", "abc", true);
    // runTestCase("aab", "cab", false);
    // runTestCase("aaabbbc", "aaabbbc" , true);
    // runTestCase("abc", "...", true);
    // runTestCase("ab", "..", true);
    // runTestCase("a", "..", false);
    // runTestCase("aa", ".", false);

    runTestCase("aa", "a", false);
    runTestCase("aa", "a*", true);
    runTestCase("ab", ".*", true);
    runTestCase("aab", "c*a*b", true);
    runTestCase("mississippi", "mis*is*ip*.", true);
    runTestCase("ab", ".*c", false);
    runTestCase("aaa", "aaaa", false);
    runTestCase("a", "ab*", true);
    runTestCase("a", ".*..a*", false);
    runTestCase("aab", "c*a*b", true);
    runTestCase("aaa", "ab*ac*a", true);
    runTestCase("aaa", "ab*a*c*a", true);
    runTestCase("aaa", "aaaa", false);
    runTestCase("a",   "ab*a", false);
    runTestCase("abcdede", "ab.*de", true);
    runTestCase("aaa", "a*a", true);
    runTestCase("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*", true);
    runTestCase("aaca", "ab*a*c*a", true);
    runTestCase("bbbba", ".*a*a", true);
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    runAllTestCases();
    printf("======================\n");
    
    char *testCaseS = "ab";
    char *testCaseP = ".*";
    // Output: true

    printf("testCase: \n");
    printf("s:%s\tp:%s\n", testCaseS, testCaseP);

    clock_t start = clock();
    bool result = isMatch(testCaseS, testCaseP);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t%s\n", (result ? "true" : "false"));

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
