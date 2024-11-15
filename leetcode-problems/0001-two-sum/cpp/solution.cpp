#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size() - 1; i++) {
            
            for (int j = 1; j < (nums.size() - i); j++) {
            
                if ((nums[i] + nums[i + j]) == target) {
                    result.push_back(i);
                    result.push_back(i + j);
                }

            }
        }

        return result;
    }
};
