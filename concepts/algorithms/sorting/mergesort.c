#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int *arrSize) {
    for (int i = 0; i < *arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// int mergeSplit(){
    
// }

/**
 * Abdul Bari (c)
 * 
 * Algorithm MergeSort(low, high)
 * if (l < h)
 *  {
 *      mid = (l + h) / 2
 *      MergeSort(l, mid)
 *      MergeSort(mid, h)
 *      Merge(l, mid, high)
 *  }
 *   ________________________________
 *  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |       Index
 *  --------------------------------
 *   ________________________________
 *  | 9 | 3 | 7 | 5 | 6 | 4 | 8 | 2 |       Array
 *  --------------------------------
 * 
 */
int *mergeSort(int* arr, int low, int high) {
    // if (low < high) {
    //     int mid = (low + high) / 2;
    //     mergeSort(arr, low, mid);
    //     mergeSort(arr, mid, high);
    //     merge(low, mid, high);
    // }
    return arr;
}

void merge(int* arr, int low, int middle, int high)
{
    return;
}


int main(int argc, char *argv[])
{
    // int arrSize = 8;
    // int l1[] = { 9, 3, 7, 5, 6, 4, 8, 2 };
    
    // printArr(l1, &arrSize);
    // int *l2 = mergeSort(l1, 0, arrSize);
    // printf("merged...\n");
    // printArr(l2, &arrSize);

    int arr[] = { 1, 3 };

    
    // printf("Res: %d\n", res);


    return 0;
}
