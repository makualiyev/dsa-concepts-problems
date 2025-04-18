"""
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
"""
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        return nums
    
    def solve(self, nums: List[int]) -> str:
        # nums = [-1,0,1,2,-1,-4]
        return self.threeSum(nums=nums)

if __name__ == '__main__':
    nums: int = [-1, 0, 1, 2, -1, -4]
    solution: Solution = Solution()
    solved: str = solution.solve(nums=nums)
    print(f"Test case: {nums}")
    print(f"Result: {solved}")