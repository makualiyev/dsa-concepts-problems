/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    -------------------------
    Topics:
    * String
    * Stack
    -------------------------
    Constraints:
    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.
    -------------------------
    Testcases:
    Input: s = "()"                                                 // Output: true
    Input: s = "()[]{}"                                             // Output: true
    Input: s = "(]"                                                 // Output: false
    Input: s = "([])"                                               // Output: true
    Input: s = "]"                                                  // Output: false


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* stack;
    int size;
    int top;
} Stack;


Stack* initStack(int size) {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->stack = (char *)malloc(sizeof(char) * size);
    st->size = size;
    st->top = -1;
    return st;
}

void pushToStack(Stack *st, char element) {
    if (st->top > st->size) {
        printf("Stack overflow!\n");
    }
    st->stack[st->top + 1] = element;
    st->top++;
}

char popFromStack(Stack *st) {
    if (st->top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    char poppedElement = st->stack[st->top];
    st->top--;
    return poppedElement;
}


bool isValid(char* s) {

    int stackSize = strlen(s);
    Stack *st = initStack(stackSize);

    for (int i = 0; i < strlen(s); i++) {
        
        if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']')) {
            if (st->top == -1)
                return false;
            char neededChar = popFromStack(st);
            if (((s[i] == ')') && (neededChar == '(')) || ((s[i] == ']') && (neededChar == '[')) || ((s[i] == '}') && (neededChar == '{')))
                continue;
            else {
                return false;
            }
        }

        pushToStack(st, s[i]);
    }

    if (st->top != -1)
    {
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    char *testCaseS = "[";
    // Output: true

    // char *testCaseS = "([])";
    // // Output: true
    
    bool result = isValid(testCaseS);
    printf("\n======================\n");
    printf("testCase\n\ts: %s\n======================\nresult:\t%s\n", testCaseS, (result ? "true" : "false"));
    return 0;
}
