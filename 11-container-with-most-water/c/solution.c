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
*/ 

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maxArea = 0;

    for (int i = 0; i < heightSize; i++)
    {
        printf("i:%d\n", i);
        for (int j = i + 1; j < heightSize; j++)
        {
            int area = ((height[j] - height[i]) < 0? height[j]: height[i]) * (j - i);
            if (area > maxArea) {
                maxArea = area;
            }
            printf("\tj:%d, area:%d\n", j, area);
        }
        
    }

    return maxArea;
}

int main(int argc, char *argv[])
{
    int height[] = { 1,8,6,2,5,4,8,3,7 };
    int heightSize = 9;

    int result = maxArea(height, heightSize);

    printf("======================\n");
    printf("testCase\nresult:\t%d\n", result);
    return 0;
}
