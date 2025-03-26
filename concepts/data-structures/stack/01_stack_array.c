/**
 * Implementation of stack from "Data Structures using C"
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

/* Array representation of stack*/
int st[MAX], top = -1;

/**
 * Step 1: IF TOP = MAX - 1
 *              PRINT "OVERFLOW"
 *              Goto STEP 4
 *          [END OF IF]
 * Step 2: SET TOP = TOP + 1
 * Step 3: SET STACK[TOP] = VALUE
 * Step 4: END
 */
void push(int st[], int val);

/**
 * Step 1: IF TOP = NULL
 *              PRINT "UNDERFLOW"
 *              Goto STEP 4
 *          [END OF IF]
 * Step 2: SET VAL = STACK[TOP]
 * Step 3: SET TOP = TOP - 1
 * Step 4: END
 */
int pop(int st[]);

/**
 * Step 1: IF TOP = NULL
 *              PRINT "STACK IS EMPTY"
 *              Goto STEP 3
 *          [END OF IF]
 * Step 2: RETURN STACK[TOP]
 * Step 3: END
 */
int peek(int st[]);

void display(int st[]);

int main(int argc, char* argv[])
{
    int val, option;
    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\nEnter the number to be pushed on stack: ");
                scanf("%d", &val);
                push(st, val);
                break;
            case 2:
                val = pop(st);
                if (val != -1)
                    printf("\n The value deleted from the stack is: %d", val);
                break;
            case 3:
                val = peek(st);
                if (val != -1)
                    printf("\n The value stored at the top of stack is: %d", val);
                break;
            case 4:
                display(st);
                break;
        }
    } while (option != 5);
    return 0;
}

void push(int st[], int val)
{
    if (top == MAX - 1) {
        printf("\n STACK OVERFLOW");
    } else {
        top++;
        st[top] = val;
    }
}

int pop(int st[])
{
    int val;
    if (top == -1) {
        printf("\n STACK UNDERFLOW");
        return -1;
    } else {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[])
{
    int i;
    if (top == -1) {
        printf("\n STACK IS EMPTY");
    } else {
        for (i = top; i >= 0; i--) {
            printf("\n %d", st[i]);
        }
        printf("\n");
    }
}

int peek(int st[])
{
    if (top == -1) {
        printf("\n STACK IS EMPTY");
        return -1;
    } else {
        return (st[top]);
    }
}