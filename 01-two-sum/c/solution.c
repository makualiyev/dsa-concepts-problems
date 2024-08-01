/*
    -------------------------
    Topics:
    * Array
    * Hash Table
    -------------------------
    Constraints:

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

    -------------------------
    Testcases:

    TESTCASE: nums = [2,7,11,15], target = 9                //  [0,1]           | Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    TESTCASE: nums = [3,2,4], target = 6                    //  [1,2]           |
    TESTCASE: nums = [3,3], target = 6                      //  [0,1]           |

    -------------------------
    C Note:
    
    The returned array must be malloced, assume caller calls free().

    -------------------------
*/

#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * (*returnSize));
    
    for (int i = 0; i < (*returnSize); i++) {
        result[i] = 2;
    }

    return result;  
}

int main(int argc, char* argv[])
{
    int nums[] = { 2, 7, 11, 15 };
    int numsSize = 4;
    int returnSize = 2;
    int target = 9;

    int *result = twoSum(nums, numsSize, target, &returnSize);
    
    printf("result: %zu", sizeof(result));

    
    return 0;
}