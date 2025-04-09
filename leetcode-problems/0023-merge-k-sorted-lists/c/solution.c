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
#include <string.h>
#include <math.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* head)
{
    struct ListNode* p = head;
    while (1) {
        if (p == NULL) {
            printf("-> *\n");
            break;
        }
        printf("-> %d ", p->val);
        p = p->next;
    }
}

void printArrOfLists(struct ListNode** listArr, int listArrSize)
{
    printf("[");
    for (int i = 0; i < listArrSize; i++) {
        printList(listArr[i]);
        printf(",");
    }
    printf("]\n");
}

void freeList(struct ListNode* head)
{
    if (head == NULL)
        return;
    freeList(head->next);
    free(head);
}

void freeArrOfLists(struct ListNode** listArr, int listArrSize)
{
    for (int i = 0; i < listArrSize; i++) {
        freeList(listArr[i]);
    }
    free(listArr);
}

struct ListNode* addNode(struct ListNode* head, int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        struct ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    return head;
}

struct ListNode* addNoderReversed(struct ListNode* head, int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(*node));
    node->val = val;
    if (head == NULL) {
        node->next = NULL;
        head = node;
    } else {
        node->next = head;
        head = node;
    }
    return head;
}

struct ListNode* buildListFromString(struct ListNode* head, char* string)
{
    // [12,3]
    int prevCounter = 1;
    
    for (int i = 1; i < (int)strlen(string); i++) {
        if (string[i] == ',' || string[i] == ']') {
            int tempVal = 0;
            int isNegative = 0;
            for (int j = prevCounter, k = 0; j < i; j++, k++) {
                if (string[j] == '-') {
                    isNegative = 1;
                    k = k - 1;
                    continue;
                }
                tempVal = tempVal + ((int)string[j] - 48) * (int)pow(10.0, (double)k);
            }
            tempVal = tempVal * (isNegative? -1: 1);
            head = addNode(head, tempVal);
            
            prevCounter = i + 1;
            continue;
        }
    }
    
    return head;
}

// struct ListNode** buildArrOfListsFromString(struct ListNode** lists, char* string, int* listsSize)
// {
//     // [[1,4,5],[1,3,4],[2,6]]
//     for (int i = 0; i < (int)strlen(string) - 1; i++) {
//         if (string[i] == ']' && string[i + 1] == ',') {
//             *listsSize = *listsSize + 1;
//         }
//     }
//     if (*listsSize == 0) {
//         return lists;
//     }
//     *listsSize = *listsSize + 1;
//     printf("\t\tDEBUG: listsSize = %d\n", *listsSize);
//     // struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * 3);
//     return lists;
// }

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    listsSize = listsSize + 1;
    return lists[0];
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    // [[1,4,5],[1,3,4],[2,6]]
    // char* listsStr = "[[1,4,5],[1,3,4],[2,6]]";
    int listsSize = 3;
    struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    struct ListNode* lists_elem_1 = NULL;
    struct ListNode* lists_elem_2 = NULL;
    struct ListNode* lists_elem_3 = NULL;
    lists_elem_1 = buildListFromString(lists_elem_1, "[1,4,5]");
    lists_elem_2 = buildListFromString(lists_elem_2, "[1,3,4]");
    lists_elem_3 = buildListFromString(lists_elem_3, "[2,6]");
    lists[0] = lists_elem_1;
    lists[1] = lists_elem_2;
    lists[2] = lists_elem_3;
    printArrOfLists(lists, listsSize);

    printf("======================\n");
    printf("testCase: \n");

    clock_t start = clock();
    struct ListNode* result = mergeKLists(lists, listsSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");

    freeArrOfLists(lists, listsSize);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
