/**
 * Linked List template for leetcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printCharArr(char** charArr, int* charArrLen)
{
    for (int i = 0; i < *charArrLen; i++) {
        printf("'%s'", charArr[i]);
    }
    printf("\n");
}