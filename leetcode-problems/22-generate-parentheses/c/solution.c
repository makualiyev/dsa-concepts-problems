/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    -------------------------
    Topics:
    * String
    * Stack
    -------------------------
    Constraints:
    1 <= n <= 8
    -------------------------
    Testcases:
    Input: n = 3                                                    // Output: ["((()))","(()())","(())()","()(())","()()()"]
    Input: n = 1                                                    // Output: ["()"]
    Input: n = 2                                                    // Output: ["(())", "()()"]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

void printResult(char** result, int* returnSize)
{
    for (int i = 0; i < *returnSize; i++) {
        printf("%s\t", result[i]);
    }
    printf("\n");
}


void backtrack(void) {
    printf("backtrack");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **strings;
    if (n == 1) {
        *returnSize = 1;
        strings = malloc(sizeof(char *) * (*returnSize));
        strings[0] = malloc(sizeof(char) * 3);
        strings[0] = "()";
    }
    return strings;
}

int main(int argc, char *argv[])
{
    int n = 1;
    // Output: ["()"]

    int returnSize = 0;

    
    char** result = generateParenthesis(n, &returnSize);
    printf("\n======================\n");
    printf("testCase\n\tn: %d\n======================\nresult:\t", n);
    printResult(result, &returnSize);
    printf("\n");
    return 0;
}
