/*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.

    -------------------------
    Topics:
    * Array
    * Two Pointers
    * Greedy
    -------------------------
    Constraints:
    n == height.length
    2 <= n <= 10^5
    0 <= height <= 10^4
    -------------------------
    Testcases:
    Input: height = [1,8,6,2,5,4,8,3,7]             // Output: 49
    Input: height = [1,1]                           // Output: 1
    Input: height = [1,2,1]                         // Output: 2
    Input: height = [8,7,2,1]                       // Output: 7
*/ 

#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int mid = heightSize % 2 ? (heightSize / 2 + 1) : (heightSize / 2);

    int i = 0;
    int j = heightSize - 1;
    int k = 0;

    while ((i < heightSize) && (j > 0)) {
        printf("\tk:%d\ti:%d\tj:%d\n", k, i, j);
        int maxAreaLocal = (height[i] < height[j] ? height[i]: height[j]) * (j - i);
        if (maxArea < maxAreaLocal) {
            maxArea = maxAreaLocal;
        }
        if (height[i] > height[j]) {
            j--;
        } else {
            i++;
        }
        k++;
        printf("\t\tk:%d\ti:%d\tj:%d\t\tmaxAreaLocal:%d\n", k, i, j, maxAreaLocal);
    }

    return maxArea;
}

int main(int argc, char *argv[])
{
    // int height[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    // int heightSize = 9;
    // int height[] = { 1, 2, 1 };
    // int heightSize = 3;
    int height[] = { 8, 7, 2, 1 };
    int heightSize = 4;

    int result = maxArea(height, heightSize);

    printf("======================\n");
    printf("testCase\nresult:\t%d\n", result);
    return 0;
}
