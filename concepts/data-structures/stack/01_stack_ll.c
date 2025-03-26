/**
 * Implementation of stack from "Data Structures using C"
 */
#include <stdio.h>
#include <stdlib.h>

/* Linked List representation of stack*/

/**
 * Step 1: Allocate memory for the new
 *          node and name it as NEW_NODE
 * Step 2: SET NEW_NODE->DATA = VAL
 * Step 3: IF TOP = NULL
 *              SET NEW_NODE->NEXT = NULL
 *              SET TOP = NEW_NODE
 *         ELSE
 *              SET NEW_NODE->NEXT = TOP
 *              SET TOP = NEW_NODE
 *         [END OF IF]
 * Step 4: END
 */
void push(int st[], int val);

/**
 * Step 1: IF TOP = NULL
 *              PRINT "UNDERFLOW"
 *              Goto STEP 5
 *          [END OF IF]
 * Step 2: SET PTR = TOP
 * Step 3: SET TOP = TOP->NEXT
 * Step 4: FREE PTR
 * Step 5: END
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
    return 0;
}