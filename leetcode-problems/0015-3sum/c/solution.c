/*
    Given an integer array nums, return all the triplets [nums[i], nums[j],
    nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
    nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.
    -------------------------
    Topics:
    * Array
    * Two Pointers
    * Sorting
    -------------------------
    Constraints:
    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5
    -------------------------
    Testcases:
    Input: nums = [-1,0,1,2,-1,-4]                  // Output: [[-1,-1,2],[-1,0,1]]
        Explanation:
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are [-1,0,1] and [-1,-1,2].
        Notice that the order of the output and the order of the triplets does not matter.

    Input: nums = [0,1,1]                           // Output: []
        Explanation:
        The only possible triplet does not sum up to 0.

    Input: nums = [0,0,0]                           // Output: [[0,0,0]]
        Explanation:
        The only possible triplet sums up to 0.

    Input: nums = [0,0,0,0]                           // Output: [[0,0,0]]
        Explanation:
        The only possible triplet sums up to 0.
    
    Input: nums = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]       // Output: ?
*/ 
#include <stdio.h>
#include <stdlib.h>

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
        for (int j = 0; j < 3; j++) {
            printf("%d%s", arrOfArrs[i][j], j == 2?"":", ");
        }
        printf("] ");
    }
    printf("\n");
}

void sortIntArr(int* arr, int* arrSize)
{
    for (int i = 1; i < *arrSize; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int t_fact(int x)
{
    if (x == 1) {
        return x;
    } else {
        return (x * t_fact(x - 1));
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // sorting the array
    sortIntArr(nums, &numsSize);
    int maxPossibleTripletsCount;
    if (numsSize <= 3)
        maxPossibleTripletsCount = 1;
    else {
        // maxPossibleTripletsCount = (int)(((float)t_fact(numsSize))/((float)t_fact(3)*(float)t_fact(numsSize - 3)));
        maxPossibleTripletsCount = 3000;
    }
    printf("maxPossibleTripletsCount:%d\n", maxPossibleTripletsCount);
    
    int** resultArr = (int **)malloc(sizeof(int *) * (maxPossibleTripletsCount));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (maxPossibleTripletsCount));

    int i = 0;
    int j = numsSize - 1;
    int targetSum = 0;
    int counter = 0;

    while (i < numsSize - 2) {
        int j = i + 1;
        while (j < numsSize - 1) {
            for (int k = j + 1; k < numsSize; k++) {
                if (nums[i] + nums[j] + nums[k] == targetSum) {
                    int checkDuplicate = 0;
                    if (counter > 0) {
                        for (int x = 0; x < counter; x++) {
                            if ((resultArr[x][0] == nums[i]) && (resultArr[x][1] == nums[j]) && (resultArr[x][2] == nums[k])) {
                                checkDuplicate = 1;
                                break;
                            }
                        }
                    }
                    if (checkDuplicate == 1)
                        break;
                    resultArr[counter] = (int *)malloc(sizeof(int) * 3);
                    (*returnColumnSizes)[counter] = 3;
                    resultArr[counter][0] = nums[i];
                    resultArr[counter][1] = nums[j];
                    resultArr[counter][2] = nums[k];
                    counter++;
                }
            }
            j++;
        }
        i++;
    }

    *returnSize = counter;
    printf("returnSize: %d\n", counter);
    return resultArr;
}

int main(int argc, char *argv[])
{
    // IN [0,0,0,0]
    // OUT [[0,0,0]]
    // int nums[] = { 0,0,0,0 };
    // int nums[] = { -1,0,1,2,-1,-4 };
    int nums[] = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
    // int nums[] = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4 };
    int numsSize = 15;
    int returnSize = 0;
    int* returnColumnSizes;

    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("======================\n");
    printf("testCase: \n");
    printIntArr(nums, &numsSize);
    printf("result:\t%d\n", numsSize);
    printArrOfIntArr(result, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}
