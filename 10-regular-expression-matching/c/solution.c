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
    Input: s = "aa", p = "a"            // Output: false
    Input: s = "aa", p = "a*"           // Output: true
    Input: s = "ab", p = ".*"           // Output: false
                                                
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct AsteriskNode {
    int position;       // asterisk position in pattern starting with the preceding element.
    char match;         // character to match.
    int isDot;          // is character to match dot or not.
    struct AsteriskNode* next;
};


struct AsteriskNode* addAsteriskNode(struct AsteriskNode* head, struct AsteriskNode* node)
{
    if (head == NULL)
    {
        head = node;
        node->next = NULL;
    }
    else {
        node->next = head;
        head = node;
    }
    return head;
}

struct AsteriskNode* decodePattern(char* p, struct AsteriskNode* head) {
    // reads pattern string and counts asterisks
    int i = 0;
    int asteriskCount = 0;

    while (true)
    {
        if (p[i] == '\0') {
            break;
        }
        if (p[i] == '*') {
            struct AsteriskNode* new_node = (struct AsteriskNode *)malloc(sizeof(struct AsteriskNode));
            if (new_node == NULL) { exit(30); }
            new_node->position = (i - 1);
            new_node->match = p[i - 1];
            new_node->isDot = p[i - 1] == '.' ? 1 : 0;

            head = addAsteriskNode(head, new_node);
            asteriskCount += 1;
        }
        i++;
    }
    return head;
}

bool simpleMatch(char* s, char* p) {
    if ((int)strlen(s) > (int)strlen(p)) {
        return false;
    }
    else {
        for (int i = 0, j = 0; i < strlen(s) && j < strlen(p); i++, j++)
        {
            if (i > j) {
                return false;
            }
            if (p[j] == '.') { continue;  }
            if (s[i] != p[j]) {
                return false;
            }
        }
        return true;
    }
}

int patternMatch(struct AsteriskNode* asterisk, int patternStartPosition, char* s, char* p)
{
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != asterisk->match) {
            if (asterisk->match == '.') {
                continue;
            }
            return 1;
        }
    }
    return 0;
}



bool isMatch(char* s, char* p) {
    struct AsteriskNode* head = NULL;
    head = decodePattern(p, head);
    

    if (head == NULL) {
        return simpleMatch(s, p);
    }

    int currPosition = 0;
    int patternMatches = 0;
    while (head != NULL)
    {
        currPosition += head->position;
        patternMatches += patternMatch(head, currPosition, s, p);
        head = head->next;
    }
    if (patternMatches) {
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    char* testCaseS = "ba";
    char* testCaseP = "b*";

    bool result = isMatch(testCaseS, testCaseP);

    printf("\ntestCase\n\ts:%s\tp:%s\nresult:\t%s\n", testCaseS, testCaseP, (result ? "true" : "false"));
    return 0;
}
