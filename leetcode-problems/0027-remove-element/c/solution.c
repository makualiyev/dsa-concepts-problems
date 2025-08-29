/*
    Given an integer array nums and an integer val, remove all occurrences of
    val in nums in-place. The order of the elements may be changed. Then return
    the number of elements in nums which are not equal to val.
    
    Consider the number of elements in nums which are not equal to val be k,
    to get accepted, you need to do the following things:
    
    * Change the array nums such that the first k elements of nums contain the
    elements which are not equal to val. The remaining elements of nums are
    not important as well as the size of nums.
    
    * Return k.

    Custom Judge:

    The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct
    length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
    
    If all assertions pass, then your solution will be accepted.

    -------------------------
    Topics:
    * Array
    * Two Pointers
    -------------------------
    Constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 50
    0 <= val <= 100
    -------------------------
    Testcases:
    Input: nums = [3,2,2,3] val = 3                 // Output: 2, nums = [2,2,_,_]
    Input: nums = [0,1,2,2,3,0,4,2] val = 2         // Output: 5, nums = [0,1,4,0,3,_,_,_]

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printIntArr(int *arr, int *arrSize)
{
    printf("[");
    for (int i = 0; i < *arrSize; i++) {
        printf("%d%s", arr[i], (i == (*arrSize - 1)? "": ","));
    }
    printf("]\n");
}

int removeElement(int* nums, int numsSize, int val) {
    int i = 0, j = numsSize - 1, k = 0;
    
    while (i <= j) {
        if (i == j) {
            if (nums[i] == val) {
                nums[i] = -1;
            } else {
                k++;
            }
            break;
        }
        if (nums[i] == val && nums[j] == val) {
            nums[j] = -1;
            j--;
            continue;
        } else if (nums[i] == val) {
            nums[i] = nums[j];
            nums[j] = -1;
            i++;
            j--;
            k++;
            continue;
        }
        i++;
        k++;
    }

    return k;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int nums[] = { 2 };
    int numsSize = 1;
    int val = 3;
    
    clock_t start = clock();
    printf("======================\n");
    printf("testCase: \n");
    printIntArr(nums, &numsSize);

    int result = removeElement(nums, numsSize, val);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    
    printf("======================\n");
    printf("result:\n");
    printIntArr(nums, &numsSize);
    printf("k = %d\n", result);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
