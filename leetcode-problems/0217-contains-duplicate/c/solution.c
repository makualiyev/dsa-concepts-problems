/*
    Given an integer array nums, return true if any value appears at least twice in the array,
    and return false if every element is distinct.

    -------------------------
    Topics:
    * Array
    * Hash Table
    * Sorting
    -------------------------
    Constraints:
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    -------------------------
    Testcases:
    Input: lists = [1,2,3,1]                        // Output: true
    Input: lists = [1,2,3,4]                        // Output: false
    Input: lists = [1,1,1,3,3,4,3,2,4,2]            // Output: true

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void printIntArr(int *arr, int arrSize)
{
    printf("[");
    for (int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    int i;
    bool isUnique = false;
    qsort(nums, (size_t)numsSize, sizeof(int), compare_ints);
    
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            isUnique = true;
            break;
        }
    }
    return isUnique;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    int nums[] = { 1,2,3,1 };
    int numsSize = 4;
    
    printf("======================\n");
    printf("testCase: \n");
    printIntArr(nums, numsSize);    

    clock_t start = clock();
    bool result = containsDuplicate(nums, numsSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t%s", (result? "true": "false"));

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
