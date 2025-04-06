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

void freeArrOfChar(char** result, int* returnSize)
{
    for (int i = 0; i < *returnSize; i++) {
        free(result[i]);
    }
    free(result);
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

int isValidParentheses(char* parentheses)
{
    int len = (int)strlen(parentheses);
    int isValid = 1;
    struct Stack* top = NULL;

    for (int i = 0; i < len; i++) {
        if (parentheses[i] == ')') {
            int popped;
            top = pop(top, &popped);
            if (popped == -1) {
                isValid = 0;
                break;
            }
            continue;
        }
        top = push(top, parentheses[i]);
    }
    
    if (peek(top) != '\0') {
        isValid = 0;
    }

    freeStack(top);
    return isValid;
}

char** multiplyParentheses(char* baseParentheses, char** currentSet, int n, int idx)
{
    if (n == idx) {
        return currentSet;
    }
    
    // for `(`, `)` it s 2^n 
    size_t baseLen = strlen(baseParentheses);
    int currentSetSize = (int)pow((double)baseLen, (double)(idx));
    int resultSetSize = (int)pow((double)baseLen, (double)(idx + 1));
    char** resultSet = (char **)malloc(sizeof(char *) * (size_t)resultSetSize);
    int counter = 0;

    if (currentSet == NULL) {
        free(resultSet);
        currentSet = (char **)malloc(sizeof(char *) * baseLen);
        for (int k = 0; k < (int)baseLen; k++) {
            currentSet[k] = malloc(sizeof(char) * 2);
            currentSet[k][0] = baseParentheses[k];
            currentSet[k][1] = '\0';
        }
        return multiplyParentheses(baseParentheses, currentSet, n, idx + 1);
    }

    for (int i = 0; i < (int)baseLen; i++) {
        for (int j = 0; j < currentSetSize; j++) {
            char* element = malloc(sizeof(char) * (size_t)(idx + 2));
            element = strcpy(element, currentSet[j]);
            element[idx] = baseParentheses[i];
            element[idx + 1] = '\0';
            resultSet[counter] = element;
            counter++;
        }
    }

    freeArrOfChar(currentSet, &currentSetSize);
    return multiplyParentheses(baseParentheses, resultSet, n, idx + 1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParentheses(int n, int* returnSize) {
    *returnSize = 0;

    int num = n * 2;
    int idx = 0;
    int currentSetSize = (int)pow(2.0, (double)num);
    char* baseParentheses = "()";
    char** currentSet = NULL;
    char** possibleParentheses = multiplyParentheses(baseParentheses, currentSet, num, idx);
    char** strings = (char **)malloc(sizeof(char *) * (size_t)currentSetSize);

    for (int i = 0; i < currentSetSize; i++) {
        if (isValidParentheses(possibleParentheses[i])) {
            strings[*returnSize] = (char *)malloc(sizeof(char) * (size_t)(num + 1));
            strings[*returnSize] = strncpy(strings[*returnSize], possibleParentheses[i], (size_t)(num + 1));
            *returnSize = *returnSize + 1;
        }
    }

    freeArrOfChar(possibleParentheses, &currentSetSize);
    return strings;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    int n = 3;
    int returnSize = 0;

    printf("======================\n");
    printf("testCase: \n");
    printf("n= %d \t|\t", n);

    clock_t start = clock();
    char** result = generateParentheses(n, &returnSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");
    printArrOfChar(result, &returnSize);
    freeArrOfChar(result, &returnSize);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
