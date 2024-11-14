#include <iostream>
#include <vector>

using namespace std;


int cmp(const void *a, const void *b)
    {
            const int *l1 = (const int*)a;
            const int *l2 = (const int*)b;
            return ((*l1 > *l2) - (*l1 < *l2));    

    };

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        int sizeOfResVector = nums1.size() + nums2.size();
        int i = 0;

        vector<int> resVec(sizeOfResVector);
        for (int j = 0; j < (int)nums1.size(); j++) {
            resVec[j] = nums1[j];
            i += 1;
        }
        for (int j = 0; j < (int)nums2.size(); j++) {
            resVec[i + j] = nums2[j];
        }
        qsort(resVec.data(), resVec.size(), sizeof(int), cmp);

        int idxMedian = 0;
        if (resVec.size() % 2) {
            idxMedian = (resVec.size() / 2) + (resVec.size() % 2);
            median = (double)resVec[idxMedian - 1];
        } else {
            idxMedian = (resVec.size() / 2) - 1;
            median = (double)(resVec[idxMedian] + resVec[idxMedian + 1]) / 2.0;
        }


        cout << "resVec.size():: " << resVec.size() << '\n';
        for (int k = 0; k < sizeOfResVector; k++) {
            cout << "resVec[" << k << "]: " << resVec[k] << endl;    
        }

        return median;
    }
};


int main(void) {
    Solution solution;
    
    // vector<int> nums1 = { 1, 3 };
    // vector<int> nums2 = { 2 };

    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };

    double result = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << "result: " << result << std::endl;
    
    return 0;
}

/*
    -------------------------
    Topics:
    
    * Array
    * Binary Search
    * Divide and Conquer
    
    -------------------------
    Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -10^6 <= nums1[i], nums2[i] <= 10^6

    -------------------------
    Testcases:

    TESTCASE1 = [1, 3] [2] // 2
    TESTCASE2 = [1, 2] [3, 4] // 2.5000

*/
