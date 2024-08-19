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
    Input: s = "aaa", p = "ab*ac*a"                 // Output: true
    Input: s = "aaa", p = "ab*a*c*a"                // Output: true

*/ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char *patternMatch(char *s, char p)
{
    int i = strlen(s) - 1;
    while (i >= 0)
    {
        if (s[i] == p)
        {
            i--;
            continue;
        } else if (p == '.') {
            i--;
            continue;
        } else {
            break;
        }
    }
    if (i == (strlen(s) - 1)) {
        return s;
    }

    i = i < 0 ? 0 : i;

    if (i == 0)
    {
        char *newS = malloc(sizeof(char));
        newS[0] = '\0';
        printf("\t\t\tpattern: %c, i: %d, newS: %s \n", p, i, newS);
        return newS;
    }

    char *newS = malloc(sizeof(char) * (i + 1 + 1));
    newS = strncpy(newS, s, sizeof(char) * (i + 1));
    newS[i + 1] = '\0';

    printf("\t\tpattern: %c, i: %d, newS: %s \n", p, i, newS);

    return newS;
}

char *simpleMatch(char *s, char p)
{
    int i = strlen(s) - 1;
    
    if (s[i] == p) {
        i--;
    } else if (p == '.') {
        i--;
    } else {
        printf("simple match failed!");
        return s;
    }

    if (i < 0)
    {
        char *newS = malloc(sizeof(char));
        newS[0] = '\0';
        printf("\t\t\t simple: %c, i: %d, newS: %s \n", p, i, newS);
        return newS;
    }

    char *newS = malloc(sizeof(char) * (i + 1 + 1));
    newS = strncpy(newS, s, sizeof(char) * (i + 1));
    newS[i + 1] = '\0';

    printf("\t\tsimple: %c, i: %d, newS: %s \n", p, i, newS);
    return newS;
}


bool isMatch(char *s, char *p)
{
    int i = strlen(p) - 1;
    int j = i - 1;
    char* nes = malloc(sizeof(char) * (strlen(s) + 1));
    nes = strcpy(nes, s);

    while (i >= 0)
    {
        int prevLen = strlen(nes);

        if (p[i] == '*') {
            printf("found pattern:%c\n", p[j]);
            nes = patternMatch(nes, p[j]);
            if (strlen(nes) == 0)
            {
                printf("DEBUG-zerostrlen\n");
            }
            i = j - 1;
            j = i - 1;
            continue;
        }
        printf("found simplt:%c\n", p[i]);
        if (strlen(nes) == 0)
        {
            return false;
        }
        nes = simpleMatch(nes, p[i]);
        if (prevLen == strlen(nes)) {
            return false;
        }
        i--;
        j--;
    }

    if (strlen(nes) > 0) {
        return false;
    }
    
    return true;
}

int main(int argc, char *argv[])
{
    // char *testCaseS = "mississippi";
    // char *testCaseP = "mis*is*ip*.";
    // char *testCaseS = "aa";
    // char *testCaseP = "a";
    // char *testCaseP = "a*";
    // char *testCaseS = "a";
    // char *testCaseP = ".*..a*";

    char *testCaseS = "aaa";
    char *testCaseP = "ab*ac*a";

    bool result = isMatch(testCaseS, testCaseP);

    printf("======================\n");
    printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    return 0;
}
