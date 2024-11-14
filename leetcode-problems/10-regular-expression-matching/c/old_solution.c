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

struct PatternNode
{
    char pattern;
    int isWildcard;
    struct PatternNode *next;
};

void printPattern(struct PatternNode *head)
{
    int i = 0;

    while (1)
    {
        if (head == NULL)
        {
            printf("\n");
            break;
        }
        printf("->");
        printf("%c%s", head->pattern, (head->isWildcard ? "*" : ""));
        head = head->next;
        i++;
    }
}

struct PatternNode *addPatternNode(struct PatternNode *head, char pattern, int isWildcard)
{
    if (head == NULL)
    {
        head = malloc(sizeof(struct PatternNode));
        head->pattern = pattern;
        head->isWildcard = isWildcard;
        head->next = NULL;
    }
    else
    {
        struct PatternNode *node = malloc(sizeof(struct PatternNode));
        node->next = head;
        node->pattern = pattern;
        node->isWildcard = isWildcard;
        head = node;
    }
    return head;
}

struct PatternNode *getSimpleNodes(struct PatternNode *head, char *pattern)
{
    int i = strlen(pattern) - 1;
    int j = i - 1;

    while (i >= 0)
    {
        if (pattern[i] == '*')
        {
            i = j - 1;
            j = i - 1;
            continue;
        }
        head = addPatternNode(head, pattern[i], 0);
        i--;
        j--;
    }

    return head;
}

struct PatternNode *getPatternNodes(struct PatternNode *head, char *pattern, int *patternsCount, int *simplePatternsCount)
{
    int i = strlen(pattern) - 1;
    int j = i - 1;

    while (i >= 0)
    {
        if (pattern[i] == '*')
        {
            head = addPatternNode(head, pattern[j], 1);
            i = j - 1;
            j = i - 1;
            *patternsCount = *patternsCount + 1;
            continue;
        }
        head = addPatternNode(head, pattern[i], 0);
        *patternsCount = *patternsCount + 1;
        *simplePatternsCount = *simplePatternsCount + 1;
        i--;
        j--;
    }

    return head;
}

int matchExpr(struct PatternNode *head, int caret, char *inputStr, int *patternsLeft, char nextSimplePattern)
{
    // wildcard match
    if (head->isWildcard)
    {
        while (caret < strlen(inputStr))
        {
            printf("\n\t\tDEBUG| pattern:%c, caret:%d, patternsLeft:%d, nextSimplePattern:%c\n", head->pattern, caret, *patternsLeft, nextSimplePattern);
            if ((strlen(inputStr) - caret) <= (*patternsLeft))
            {
                printf("\t\tdebugg-1\n");
                break;
                //  0   1   2   3   4   5   6
                //  a   b   c   d   e   d   e
                //  strlen(s) = 7 - 5
            }

            if ((head->pattern == '.') || (inputStr[caret] == head->pattern))
            {
                caret = caret + 1;
                continue;
            }
            else
            {
                return caret;
            }
        }
    }
    // simple match
    else
    {
        if ((head->pattern == '.') || (inputStr[caret] == head->pattern))
        {
            caret = caret + 1;
            return caret;
        }
    }

    return caret;
}

bool isMatch(char *s, char *p)
{
    /*
        decoding regex by constructing a linked list
        of its components
    */
    struct PatternNode *patternHead = NULL;
    struct PatternNode *simplePatternHead = NULL;
    int patternsCount = 0;
    int simplePatternsCount = 0;
    patternHead = getPatternNodes(patternHead, p, &patternsCount, &simplePatternsCount);
    simplePatternHead = getSimpleNodes(simplePatternHead, p);

    printPattern(patternHead);
    printPattern(simplePatternHead);
    printf("\t\tpatternsCount:%d, simplePatternsCount:%d\n", patternsCount, simplePatternsCount);

    // main loop
    int i = 1; // for all patterns
    int j = 1; // for simple patterns
    int caret = 0;
    int patternsLeft = 0;
    int simplePatternsLeft = simplePatternsCount;
    int patternsSuccess = 0;
    char nextSimplePattern = simplePatternHead != NULL ? simplePatternHead->pattern : '\n';

    while (1)
    {
        if (patternHead == NULL)
        {
            break;
        }

        printf("DEBUG|start caret was -> %d\t%c%s", caret, patternHead->pattern, patternHead->isWildcard ? "*" : "");
        patternsLeft = patternsCount - i;

        if (!patternHead->isWildcard)
        {
            if (simplePatternHead != NULL)
            {
                simplePatternHead = simplePatternHead->next;
                if (simplePatternHead != NULL)
                {
                    nextSimplePattern = simplePatternHead->pattern;
                }
                else
                {
                    nextSimplePattern = '\n';
                }
            }
            else
            {
                nextSimplePattern = '\n';
            }

            simplePatternsLeft = simplePatternsCount - j;
            j++;
        }

        if ((caret == strlen(s)) && (!patternHead->isWildcard))
        {
            printf("\t\tDEBUG --- what is?\n");
            return false;
        }

        if ((patternHead->isWildcard) && (patternHead->pattern == '.')) {

            int isChecked = 0;

            while (patternHead != NULL)
            {
                if (!patternHead->isWildcard) {
                    if (simplePatternsLeft < (strlen(s) - i))
                    {
                        return false;
                    }
                    for (int k = caret; k < strlen(s); k++)
                    {
                        if ((patternHead->pattern == '.') || (s[k] == patternHead->pattern))
                        {
                            caret = k;
                            isChecked++;
                            break;
                        }
                    }
                }

                i++;
                patternHead = patternHead->next;
            }

            if (isChecked == simplePatternsLeft) {
                printf("\t\tdebug|true| isChecked: %d, simplePatternsLeft: %d, caret: %d \n", isChecked, simplePatternsLeft, caret);
                return true;
            } else {
                printf("\t\tdebug|false| isChecked: %d, simplePatternsLeft: %d, caret: %d \n", isChecked, simplePatternsLeft, caret);
                return false;
            }
            
        }


        int newCaret = matchExpr(patternHead, caret, s, &simplePatternsLeft, nextSimplePattern);


        // successes patterns
        if ((newCaret == caret) && (patternHead->isWildcard))
        {
            patternsSuccess++;
        }
        else if ((newCaret > caret) && (patternHead->isWildcard))
        {
            patternsSuccess++;
        }
        else if ((newCaret > caret) && (!patternHead->isWildcard))
        {
            patternsSuccess++;
        }
        else
        {
            printf("\n\t\t\tnewCaret to caret:0\n");
        }

        caret = newCaret;
        printf("\tcaret now -> %d", caret);
        printf("\tpatternsLeft now -> %d\n", simplePatternsLeft);

        i++;
        patternHead = patternHead->next;
    }

    printf("\n\npatternsSuccess:%d, patternsCount:%d\n\n", patternsSuccess, patternsCount);
    if (caret < strlen(s))
    {
        return false;
    }

    if (patternsCount == patternsSuccess)
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}

void matchCases(void)
{
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aa", "a") ? "true" : "false", "false", "aa", "a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aa", "a*") ? "true" : "false", "true", "aa", "a*");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("ab", ".*") ? "true" : "false", "true", "ab", ".*");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aab", "c*a*b") ? "true" : "false", "true", "aab", "c*a*b");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("mississippi", "mis*is*ip*.") ? "true" : "false", "true", "mississippi", "mis*is*ip*.");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("ab", ".*c") ? "true" : "false", "false", "ab", ".*c");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaa", "aaaa") ? "true" : "false", "false", "aaa", "aaaa");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("a", "ab*") ? "true" : "false", "true", "a", "ab*");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("a", ".*..a*") ? "true" : "false", "false", "a", ".*..a*");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aab", "c*a*b") ? "true" : "false", "true", "aab", "c*a*b");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaa", "ab*ac*a") ? "true" : "false", "true", "aaa", "ab*ac*a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaa", "aaaa") ? "true" : "false", "false", "aaa", "aaaa");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("a", "ab*a") ? "true" : "false", "false", "a", "ab*a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaa", "ab*a*c*a") ? "true" : "false", "true", "aaa", "ab*a*c*a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("abcdede", "ab.*de") ? "true" : "false", "true", "abcdede", "ab.*de");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaa", "a*a") ? "true" : "false", "true", "aaa", "a*a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*") ? "true" : "false", "true", "aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("aaca", "ab*a*c*a") ? "true" : "false", "true", "aaca", "ab*a*c*a");
    printf("r:%s\te:%s\ts:%s p:%s\t\n", isMatch("bbbba", ".*a*a") ? "true" : "false", "true", "bbbba", ".*a*a");

    //  a   a   b   c   b   c   b   c   a   c   c   b   c   a   a   b   c
    //  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16

    //
    //  .*                          a*  a   a*  .*  b*  .   c*  .*          a*
    //  a   a   b   c   b   c   b   c   a   c   c   b   c   a   a   b   c

    //  .*  a   a*  .*  b*  .   c*  .*          a*
    //  a   a   b   c   b   c   b   c   a   c   c   b   c   a   a   b   c

    //  0   1   2   3   4   5   6   7   8   9
    //  1   2   3   4   5   6   7   8   9   10
}

int main(int argc, char *argv[])
{
    // char *testCaseS = "aaa";
    // char *testCaseP = "ab*a*c*a";
    // // Output: true

    // char *testCaseS = "abcdede";
    // char *testCaseP = "ab.*de";
    // // Output: true

    // char *testCaseS = "aa";
    // char *testCaseP = "a";
    // // Output: false

    char *testCaseS = "aaa";
    char *testCaseP = "a*a";
    // Output: true

    // char *testCaseS = "aabcbcbcaccbcaabc";
    // char *testCaseP = ".*a*aa*.*b*.c*.*a*";
    // // Output: true

    // char *testCaseS = "aaca";
    // char *testCaseP = "ab*a*c*a";
    // // Output: true

    // char *testCaseS = "a";
    // char *testCaseP = ".*..a*";
    // //  Output: false

    bool result = isMatch(testCaseS, testCaseP);

    printf("\n======================\n");
    printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));

    // matchCases();

    return 0;
}
