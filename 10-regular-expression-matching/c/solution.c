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


struct TreeNode {
    char* value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode *createTreeNode(char* value) {
    struct TreeNode *result = malloc(sizeof(struct TreeNode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTree(struct TreeNode *root, int level)
{
    if (root == NULL)
                return;
        for (int i = 0; i < level; i++)
                printf(i == level - 1 ? "|-" : "  ");
        printf("%s\n", root->value);
        printTree(root->left, level + 1);
        printTree(root->right, level + 1);
}

bool isMatch(char *s, char *p)
{
    // decisionTree?
    // length?
    // TOP down memoization?
    // backtracking?
    struct TreeNode *root = createTreeNode("1");
    struct TreeNode *n_1_1 = createTreeNode("1.1");
    struct TreeNode *n_1_2 = createTreeNode("1.2");
    struct TreeNode *n_1_1_1 = createTreeNode("1.1.1");
    struct TreeNode *n_1_1_2 = createTreeNode("1.1.2");

    root->left = n_1_1;
    root->right = n_1_2;
    n_1_1->left = n_1_1_1;
    n_1_1->right = n_1_1_2;

    printTree(root, 0);


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

    char *testCaseS = "aa";
    char *testCaseP = "a";
    // Output: false

    // char *testCaseS = "aaa";
    // char *testCaseP = "a*a";
    // // Output: true

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
