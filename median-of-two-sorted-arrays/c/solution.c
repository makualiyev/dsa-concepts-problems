#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* resArr = malloc(sizeof(int) * (nums1Size + nums2Size));


    int i = 0;
    while (i < (nums1Size + nums2Size)) 
    {
        if ((i < (nums1Size)) && (i < (nums2Size))) {
            resArr[i] = nums1[i];
            resArr[i + 1] = nums2[i];
            i += 2;
            continue;
        } else if (i < nums1Size) {
            resArr[i] = nums1[i];
            i++;
            continue;
        } else if (i < nums2Size) {
            resArr[i] = nums2[i];
            i++;
            continue;
        } else {
            break;
        }
        i++;
    }
    
    for (int i = 0; i < (nums1Size + nums2Size); i++) {
        printf("func:findMedian| i: %d\tresArr[i]: %d\n", i, resArr[i]);
    }
    printf("func:findMedian| nums1[0]: %d; nums2[0]: %d\n", nums1[0], nums2[0]);
    return 2.5;
}

int main(int argc, char* argv[])
{
    int nums1Size = 2;
    int nums2Size = 1;
    int nums1[] = { 1, 3 };
    int nums2[] = { 2 };
    

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("result: %f\n", result);
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