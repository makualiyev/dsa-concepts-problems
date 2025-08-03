/*
    Given an integer array nums sorted in non-decreasing order, remove
    the duplicates in-place such that each unique element appears only
    once. The relative order of the elements should be kept the same.
    Then return the number of unique elements in nums.

    Consider the number of unique elements of nums to be k, to get accepted,
    you need to do the following things:

    * Change the array nums such that the first k elements of nums contain
    the unique elements in the order they were present in nums initially.
    The remaining elements of nums are not important as well as the size of
    nums.
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
    1 <= nums.length <= 3 * 10^4
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.
    -------------------------
    Testcases:
    Input: nums = [1,1,2]                           // Output: 2, nums = [1,2,_]
                                                    // Explanation:
                                                            Your function should return k = 2, with the first two elements
                                                            of nums being 1 and 2 respectively. It does not matter what you
                                                            leave beyond the returned k (hence they are underscores).

    Input: nums = [0,0,1,1,1,2,2,3,3,4]             // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
                                                    // Explanation:
                                                            Your function should return k = 5, with the first five elements
                                                            of nums being 0, 1, 2, 3, and 4 respectively. It does not matter
                                                            what you leave beyond the returned k (hence they are underscores).
    Input: nums = [1,2]                             // Output: 2
    Input: nums = [1,1]                             // Output: 1

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

int removeDuplicates(int* nums, int numsSize) {
    return numsSize;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    int nums[] = { 1, 1, 2 };
    int numsSize = 3;
    
    clock_t start = clock();
    int result = removeDuplicates(nums, numsSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \n");
    printIntArr(nums, &numsSize);
    printf("result:\t");
    printf("k = %d\n", result);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
