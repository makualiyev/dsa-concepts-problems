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
    Input: s = "aaa", p = "aaaa"                    // Output: false
    Input: s = "a",   p = "ab*a"                    // Output: false

*/ 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct PatternNode {
    char pattern;
    int isAsterisk;
    struct PatternNode *next;
};


void printPattern(struct PatternNode *head)
{
    int i = 0;
    while (1)
    {
        if (head == NULL) {
            break;
        }
        printf("%d->%c:%d\n", i, head->pattern, head->isAsterisk);
        head = head->next;
        i++;
    }
}

struct PatternNode *addPatternNode(struct PatternNode *head, char pattern, int isAsterisk)
{
    if (head == NULL)
    {
        head = malloc(sizeof(struct PatternNode*));
        head->pattern = pattern;
        head->isAsterisk = isAsterisk;
        head->next = NULL;
    } else  {
        struct PatternNode *node = malloc(sizeof(struct PatternNode*));
        node->next = head;
        head = node;
    }
    return head;
}

struct PatternNode *getPatternNodes(struct PatternNode *head, char *pattern)
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
            continue;
        }
        head = addPatternNode(head, pattern[i], 0);
        i--;
        j--;
    }
    return head;
}

bool isMatch(char *s, char *p)
{
    struct PatternNode* patternHead = NULL;
    patternHead = getPatternNodes(patternHead, p);
    printPattern(patternHead);
    
    return true;
}

int main(int argc, char *argv[])
{
    char *testCaseS = "aaa";
    char *testCaseP = "ab*a*c*a";

    bool result = isMatch(testCaseS, testCaseP);

    printf("======================\n");
    printf("testCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    return 0;
}
