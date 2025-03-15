/**
 * https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
 * (C) GeeksforGeeks
 * Method 1 (Fix Elements and Recur) 
 */
#include <stdio.h>

void combinationUtil(int arr[], int data[], int start, int end, int index, int r);

/**
 * The main function that prints all combinations of size r
 * in arr[] of size n. This function mainly uses combinationUtil()
 */
void printCombination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n - 1, 0, r);
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
    if (index == r) {
        for (int j = 0; j < r; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1, end, index + 1, r);
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int r = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, r);
}