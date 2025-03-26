/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    -------------------------
    Topics:
    * String
    * Dynamic Programming
    * Backtracking
    -------------------------
    Constraints:
    1 <= n <= 8
    -------------------------
    Testcases:
    Input: n = 3                                                    // Output: ["((()))","(()())","(())()","()(())","()()()"]
    Input: n = 1                                                    // Output: ["()"]
    Input: n = 2                                                    // Output: ["(())", "()()"]
    Input: n = 4                                                    // Output: ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BUFFER_SIZE 4096

struct Stack {
    char val;
    struct Stack *next;
};

struct Stack* push(struct Stack* top, char val)
{
    struct Stack* new_node = (struct Stack *)malloc(sizeof(*new_node));
    new_node->val = val;
    if (top == NULL) {
        top = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = top;
        top = new_node;
    }
    return top;
}

struct Stack* pop(struct Stack* top, int* popped)
{
    if (top == NULL) {
        // printf("Stack is empty!");
        *popped = -1;
        return top;
    }
    struct Stack* temp = top;
    *popped = temp->val;
    top = top->next;
    free(temp);
    return top;
}

char peek(struct Stack* top)
{
    if (top == NULL) {
        // printf("Stack is empty!");
        return '\0';
    }
    return top->val;
}

void freeStack(struct Stack* top)
{
    if (top == NULL)
        return;
    freeStack(top->next);
    free(top);
}

void printStack(struct Stack* top)
{
    printf("\n[");
    struct Stack* temp = top;
    while (temp != NULL) {
        printf("%c ", temp->val);
        temp = temp->next;
    }
    printf("]\n");
}

void printArrOfChar(char** result, int* returnSize)
{
    for (int i = 0; i < *returnSize; i++) {
        printf("%s\t", result[i]);
    }
    printf("\n");
}

void swapChars(char* a, char* b)
{
    char temp;
    temp = *a; 
    *a = *b;
    *b = temp;
    return;
}

int isValidParenthesis(char* parenthesis)
{
    int len = (int)strlen(parenthesis);
    int isValid = 1;
    struct Stack* top = NULL;

    for (int i = 0; i < len; i++) {
        if (parenthesis[i] == ')') {
            int popped;
            top = pop(top, &popped);
            if (popped == -1) {
                isValid = 0;
                break;
            }
            continue;
        }
        top = push(top, parenthesis[i]);
    }
    
    if (peek(top) != '\0') {
        isValid = 0;
    }

    freeStack(top);
    return isValid;
}

/**
 * using `backtracking`
 */
void permuteParenthesis(char* parenthesis, int index, int length, char** strings, int* returnSize)
{
    if (index == length - 1) {
        if (isValidParenthesis(parenthesis)) {
            if (*returnSize > 0) {
                for (int j = 0; j < *returnSize; j++) {
                    if (strncmp(strings[j], parenthesis, (size_t)length) == 0) {
                        return;
                    }
                }
            }
            size_t newLen = (size_t)(length + 1);
            strings[*returnSize] = (char *)malloc(sizeof(char) * newLen);
            strings[*returnSize] = strncpy(strings[*returnSize], parenthesis, newLen);
            *returnSize = *returnSize + 1;
        }
        return;
    }

    for (int i = 0; i < length; i++) {
        swapChars(&parenthesis[index], &parenthesis[i]);
        permuteParenthesis(parenthesis, index + 1, length, strings, returnSize);
        swapChars(&parenthesis[index], &parenthesis[i]);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int len = n * 2;
    int maxPossibleCombo = (int)pow(2.0, (double)n);
    char* baseParenthesis = malloc(sizeof(char) * (size_t)(len + 1));
    char **strings = (char **)malloc(sizeof(char *) * (size_t)(maxPossibleCombo * 2));

    for (int i = 0, j = n; j < len; i++, j++) {
        baseParenthesis[i] = '(';
        baseParenthesis[j] = ')';
    }
    baseParenthesis[len] = '\0';

    permuteParenthesis(baseParenthesis, 0, len, strings, returnSize);
    
    free(baseParenthesis);
    return strings;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    int n = 5;
    int returnSize = 0;

    printf("======================\n");
    printf("testCase: \n");
    printf("n= %d \t|\t", n);

    clock_t start = clock();
    char** result = generateParenthesis(n, &returnSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");
    printArrOfChar(result, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
