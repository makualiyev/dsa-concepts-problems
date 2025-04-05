/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.

    -------------------------
    Topics:
    * Linked List
    * Divide and Conquer
    * Heap (Priority Queue)
    * Merge Sort
    -------------------------
    Constraints:
    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 10^4.
    -------------------------
    Testcases:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]                  // Output: [1,1,2,3,4,4,5,6]
                                                               Explanation: The linked lists are:
                                                                    [
                                                                        1->4->5,
                                                                        1->3->4,
                                                                        2->6
                                                                        ]
                                                                    merging them into one sorted list:
                                                                        1->1->2->3->4->4->5->6
    Input: lists = []                                       // Output: []
    Input: lists = [[]]                                     // Output: []

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return lists[0];
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    struct ListNode** lists;
    int listsSize = 3;


    printf("======================\n");
    printf("testCase: \n");

    clock_t start = clock();
    char** result = mergeKLists(lists, listsSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
