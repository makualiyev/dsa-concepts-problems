/*
    Given an integer array nums of length n and an integer target, find three integers
    in nums such that the sum is closest to target.

    Return the sum of the three integers.

    You may assume that each input would have exactly one solution.
    -------------------------
    Topics:
    * Array
    * Two Pointers
    * Sorting
    -------------------------
    Constraints:
    3 <= nums.length <= 500
    -1000 <= nums[i] <= 1000
    -10^4 <= target <= 10^4
    -------------------------
    Testcases:
    Input: nums = [-1,2,1,-4], target = 1                   // Output: 2
        Explanation:
        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

    Input: nums = [0,0,0], target = 1                       // Output: 0
        Explanation:
        The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
    
    Input: nums = [10,20,30,40,50,60,70,80,90], target = 1      // Output: 60
    Input: nums = [4,0,5,-5,3,3,0,-4,-5], target = -2           // Output: -2
    Input: nums = [0,0,0], target = 10000                       // Output: 0
    
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntArr(int* arr, int* arrSize)
{
    for (int i = 0; i < *arrSize; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
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

int* minimizeArr(int *arr, int *arrSize, int *newArrSize)
{
    int *newArr = (int *)malloc(sizeof(int) * (size_t)(*arrSize));
    int counter = 0;
    int uniqueCounter = 0;
    int lastAdded = 0;
    int i = 0;
    
    while (i < *arrSize) {
        if (i > 0 && arr[i] == lastAdded) {
            if (uniqueCounter > 2) {
                uniqueCounter++;
                i++;
                continue;
            } 
            newArr[counter] = lastAdded;
            counter++;
            uniqueCounter++;
            i++;
            continue;
        }
        
        lastAdded = arr[i];
        newArr[counter] = lastAdded;
        uniqueCounter = 1;
        counter++;
        i++;
    }
    
    if (counter == 2) {
        newArr[counter] = newArr[counter - 1];
        counter++;
    }
    
    *newArrSize = counter;
    return newArr;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, (size_t)numsSize, sizeof(int), compare_ints);
    int tempNumsSize = 0;
    int *tempNums = minimizeArr(nums, &numsSize, &tempNumsSize);
    // printf("--------------------------------MINIMIZED -------------------\n");
    // printIntArr(tempNums, &tempNumsSize);
    // printf("-------------------------------------------------------------\n");

    

    int resultSum = 0;
    int minDiff = 100000;
    int diffSign = 1;
    int i = 0;

    if (tempNumsSize == 3) {
        resultSum = tempNums[0] + tempNums[1] + tempNums[2];
        free(tempNums);
        return resultSum;    
    }

    while (i < tempNumsSize - 2) {
        int j = i + 1;
        
        while (j < tempNumsSize - 1) {
            int k = j + 1;
            while (k < tempNumsSize) {
                int tempNumsSum = tempNums[i] + tempNums[j] + tempNums[k];
                // printf("\tDEBUG i:%d\tj:%d\tk:%d\tTEMPNUMSSUM:%d\n", i, j, k, tempNumsSum);
                if (abs(target - tempNumsSum) < minDiff) {
                    minDiff = abs(target - tempNumsSum);
                    diffSign = target - tempNumsSum < 0 ? 1: -1;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    
    // printf("DEBUG\ttarget:%d\tminDiff:%d\tdiffSign:%d\n", target, minDiff, diffSign);
    if (diffSign == 1) {
        resultSum = target + minDiff;
    } else {
        resultSum = target - minDiff;
    }
    free(tempNums);
    return resultSum;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);

    // int nums[] = { 10,20,30,40,50,60,70,80,90 };
    // -4, -1, 1, 2

    // int nums[] = { 4,0,5,-5,3,3,0,-4,-5 };
    // int numsSize = 9;
    // int target = - 2;
    int nums[] = { 0,0,0 };
    int numsSize = 3;
    int target = 10000;

    clock_t start = clock();
    int result = threeSumClosest(nums, numsSize, target);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \ntarget:%d\t", target);
    printIntArr(nums, &numsSize);
    printf("result:\t%d\n", result);
    printf("Time elapsed: %.4f\n", seconds);

    return 0;
}
