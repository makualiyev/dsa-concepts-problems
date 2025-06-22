/*
    Given an array nums of n integers, return an array of all the unique quadruplets
    [nums[a], nums[b], nums[c], nums[d]] such that:

        * 0 <= a, b, c, d < n
        * a, b, c, and d are distinct.
        * nums[a] + nums[b] + nums[c] + nums[d] == target
    
    You may return the answer in any order.

    -------------------------
    Topics:
    * Array
    * Two Pointers
    * Sorting
    -------------------------
    Constraints:
    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
    -------------------------
    Testcases:
    Input: nums = [1,0,-1,0,-2,2], target = 0                                                   // Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    Input: nums = [2,2,2,2,2], target = 8                                                       // Output: [[2,2,2,2]]
    Input: nums = [0,0,0], target = 0                                                           // Output: [[]]
    Input: nums = [-3,-1,0,2,4,5], target = 0                                                   // Output: [[-3,-1,0,4]]
    Input: nums = [-3,-2,-1,0,0,1,2,3], target = 0                                              // Output: [
                                                                                                    [-3,-2,2,3],[-3,-1,1,3],[-3,0,0,3],
                                                                                                    [-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],
                                                                                                    [-2,0,0,2],[-1,0,0,1]]
    Input: nums = [-5,-4,-3,-2,-1,0,0,1,2,3,4,5], target = 0                                    // Output: [
                                                                                                        [-5,-4,4,5],[-5,-3,3,5],[-5,-2,2,5],
                                                                                                        [-5,-2,3,4],[-5,-1,1,5],[-5,-1,2,4],
                                                                                                        [-5,0,0,5],[-5,0,1,4],[-5,0,2,3],
                                                                                                        [-4,-3,2,5],[-4,-3,3,4],[-4,-2,1,5],
                                                                                                        [-4,-2,2,4],[-4,-1,0,5],[-4,-1,1,4],
                                                                                                        [-4,-1,2,3],[-4,0,0,4],[-4,0,1,3],
                                                                                                        [-3,-2,0,5],[-3,-2,1,4],[-3,-2,2,3],
                                                                                                        [-3,-1,0,4],[-3,-1,1,3],[-3,0,0,3],
                                                                                                        [-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],
                                                                                                        [-2,0,0,2],[-1,0,0,1]
                                                                                                        ]
    Input: nums = [1000000000,1000000000,1000000000,1000000000], target = -294967296            // Output: [[]]
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

void printArrOfIntArr(int** arrOfArrs, int* arrSize)
{
    for (int i = 0; i < *arrSize; i++) {
        printf("[");
        for (int j = 0; j < 4; j++) {
            printf("%d%s", arrOfArrs[i][j], j == 3?"":", ");
        }
        printf("] ");
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

int t_fact(int x)
{
    if (x == 1) {
        return x;
    } else {
        return (x * t_fact(x - 1));
    }
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
            if (uniqueCounter > 3) {
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
    
    if (counter == 3) {
        newArr[counter] = newArr[counter - 1];
        counter++;
    }
    
    *newArrSize = counter;
    return newArr;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 4) {
        int** resultArr = (int **)malloc(sizeof(int *));
        *returnColumnSizes = (int *)malloc(sizeof(int));
        (*returnColumnSizes)[0] = 0;
        *returnSize = 0;
        return resultArr;
    }

    int testInt = 1000000000;
    printf("testing int %d\n", testInt);
    
    qsort(nums, (size_t)numsSize, sizeof(int), compare_ints);
    int tempNumsSize = 0;
    int *tempNums = minimizeArr(nums, &numsSize, &tempNumsSize);
    printf("--------------------------------MINIMIZED -------------------\n");
    printIntArr(tempNums, &tempNumsSize);
    printf("-------------------------------------------------------------\n");

    int maxPossibleTripletsCount;
    if (numsSize <= 4)
        maxPossibleTripletsCount = 1;
    else {
        maxPossibleTripletsCount = tempNumsSize * 10;
    }
    // printf("maxPossibleTripletsCount:%d\n", maxPossibleTripletsCount);
    
    int** resultArr = (int **)malloc(sizeof(int *) * (size_t)(maxPossibleTripletsCount));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (size_t)(maxPossibleTripletsCount));

    int i = 0;
    int counter = 0;
    int dirCounter = 0;

    while (i < tempNumsSize) {
        int j = tempNumsSize - 1;
        while (j > 0) {
            int k = 0;
            int m = tempNumsSize - 1;
            long tempTargetSum = (long)target - ((long)tempNums[i] + (long)tempNums[j]);
            while (k < m) {
                if (k == j || k == i) {
                    k++;
                    continue;
                } else if (m == i || m == j) {
                    m--;
                    continue;
                } else {
                    /**
                     * printf("DEBUG:\ttargetSum:%d\t[i:%d]tempNums[i]:%d\t[j:%d]tempNums[j]:%d\t[k:%d]tempNums[k]:%d\t[m:%d]tempNums[m]:%d\n", \
                     * tempTargetSum, i, tempNums[i], j, tempNums[j], k, tempNums[k], m, tempNums[m]);
                     */
                    if (tempNums[k] + tempNums[m] == tempTargetSum) {
                        if (i == j || i == k || i == m || j == k || j == m || k == m) {
                            break;
                        }
                        int tempCmpArr[] = { tempNums[i], tempNums[j], tempNums[k], tempNums[m] };
                        qsort(tempCmpArr, 4, sizeof(int), compare_ints);
                        int checkDuplicate = 0;
                        if (counter > 0) {
                            for (int x = 0; x < counter; x++) {
                                if ((resultArr[x][0] == tempCmpArr[0]) && (resultArr[x][1] == tempCmpArr[1]) && (resultArr[x][2] == tempCmpArr[2])
                                        && (resultArr[x][3] == tempCmpArr[3])) {
                                    checkDuplicate = 1;
                                    break;
                                }
                            }
                        }
                        if (checkDuplicate == 1) {
                            k++;
                            continue;
                        }
                        resultArr[counter] = (int *)malloc(sizeof(int) * 4);
                        (*returnColumnSizes)[counter] = 4;
                        resultArr[counter][0] = tempCmpArr[0];
                        resultArr[counter][1] = tempCmpArr[1];
                        resultArr[counter][2] = tempCmpArr[2];
                        resultArr[counter][3] = tempCmpArr[3];
                        counter++;
                        k++;
                    } else if (tempNums[k] + tempNums[m] > tempTargetSum) {
                        m--;
                    } else {
                        k++;
                    }
                }

                }
                j--;
            }
        i++;

    }

    
    free(tempNums);
    
    *returnSize = counter;
    printf("returnSize: %d\n", counter);
    return resultArr;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");

    /**
     * Input: nums = [-3,-2,-1,0,0,1,2,3], target = 0          // Output: [
     * not found =>  [-3,-2,0,5],[-5,0,2,3]
     */
    
    int nums[] = { 1000000000,1000000000,1000000000,1000000000 };
    int numsSize = 4;
    int target = -294967296;
    int returnSize = 0;
    int* returnColumnSizes;

    clock_t start = clock();
    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \n");
    printIntArr(nums, &numsSize);
    printf("result:\t");
    printArrOfIntArr(result, &returnSize);
    printf("\nTime elapsed: %.4f\n", seconds);

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}
