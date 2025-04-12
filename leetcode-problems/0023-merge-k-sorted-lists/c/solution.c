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
    Input: lists = [[],[1]]                                 // Output: [1]
    Input: lists = [[7],[49],[73],[58],[30]]                // Output: [7,30,49,58,73]

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

void printIntArr(int *arr, int arrSize)
{
    printf("[");
    for (int i = 0; i < arrSize; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

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

int getSizeOfList(struct ListNode* head)
{
    int listSize = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        p = p->next;
        listSize++;
    }
    return listSize;
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

struct ListNode* mergeLists(struct ListNode* list_l, struct ListNode* list_r)
{
    struct ListNode* merged = NULL;
    struct ListNode* temp_l = list_l;
    struct ListNode* temp_r = list_r;

    while ((temp_l != NULL) && (temp_r != NULL)) {
        if (temp_l->val <= temp_r->val) {
            merged = addNode(merged, temp_l->val);
            temp_l = temp_l->next;
        } else {
            merged = addNode(merged, temp_r->val);
            temp_r = temp_r->next;
        }
    }

    while (temp_l != NULL) {
        merged = addNode(merged, temp_l->val);
        temp_l = temp_l->next;
    }
    while (temp_r != NULL) {
        merged = addNode(merged, temp_r->val);
        temp_r = temp_r->next;
    }

    return merged;
}

// struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
//     struct ListNode* merged = NULL;
    
//     if (listsSize == 0) {
//         return merged;
//     }
//     if (listsSize == 1) {
//         return lists[0];
//     }
    
//     int i = 2;
//     struct ListNode* tempMerged = mergeLists(lists[0], lists[1]);

//     if (listsSize == 2) {
//         merged = tempMerged;
//         return merged;
//     }
//     while (i < listsSize)
//     {
//         merged = mergeLists(tempMerged, lists[i]);
//         freeList(tempMerged);
//         tempMerged = merged;
//         i++;
//     }

//     return merged;
// }


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* merged = NULL;
    
    if (listsSize == 0) {
        return merged;
    }
    if (listsSize == 1) {
        return lists[0];
    }
    
    int newArrSize = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* temp;
        temp = lists[i];
        while (temp != NULL) {
            temp = temp->next;
            newArrSize++;
        }
    }
    int* listsAsArr = malloc(sizeof(int) * (size_t)newArrSize);

    int counter = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* temp;
        temp = lists[i];
        int j = 0;
        while (temp != NULL) {
            listsAsArr[counter] = temp->val;
            temp = temp->next;
            j++;
            counter++;
        }
    }
    qsort(listsAsArr, (size_t)counter, sizeof(int), compare_ints);

    for (int i = 0; i < counter; i++) {
        merged = addNode(merged, listsAsArr[i]);
    }

    free(listsAsArr);
    return merged;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    // [[1,4,5],[1,3,4],[2,6]]
    int listsSize = 3;
    struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * (size_t)listsSize);
    struct ListNode* lists_elem_1 = NULL;
    struct ListNode* lists_elem_2 = NULL;
    struct ListNode* lists_elem_3 = NULL;
    lists_elem_1 = buildListFromString(lists_elem_1, "[1,4,5]");
    lists_elem_2 = buildListFromString(lists_elem_2, "[1,3,4]");
    lists_elem_3 = buildListFromString(lists_elem_3, "[2,6]");
    lists[0] = lists_elem_1;
    lists[1] = lists_elem_2;
    lists[2] = lists_elem_3;

    // // [[],[1]]
    // int listsSize = 2;
    // struct ListNode** lists = (struct ListNode**)malloc(sizeof(struct ListNode*) * (size_t)listsSize);
    // struct ListNode* lists_elem_1 = NULL;
    // struct ListNode* lists_elem_2 = NULL;
    // lists_elem_2 = buildListFromString(lists_elem_2, "[1]");
    // lists[0] = lists_elem_1;
    // lists[1] = lists_elem_2;

    printArrOfLists(lists, listsSize);

    printf("======================\n");
    printf("testCase: \n");

    clock_t start = clock();
    struct ListNode* result = mergeKLists(lists, listsSize);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");
    printList(result);
    freeList(result);
    freeArrOfLists(lists, listsSize);

    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
