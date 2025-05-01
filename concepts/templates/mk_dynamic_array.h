/**
 * Dynamic Array template for leetcode
 */

 #include <stdio.h>

void printIntArr(int *arr, int *arrSize)
{
    printf("[");
    for (int i = 0; i < *arrSize; i++) {
        printf("%d%s", arr[i], (i == (*arrSize - 1)? "": ","));
    }
    printf("]\n");
}