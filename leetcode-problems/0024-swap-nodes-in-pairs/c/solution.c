/*
    Given a linked list, swap every two adjacent nodes and return its head.
    You must solve the problem without modifying the values in the list's nodes
    (i.e., only nodes themselves may be changed.)

    -------------------------
    Topics:
    * Recursion
    * Linked List
    -------------------------
    Constraints:
    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
    -------------------------
    Testcases:
    Input: head = [1,2,3,4]                                 // Output: [2,1,4,3]
    Input: head = []                                        // Output: []
    Input: head = [1]                                       // Output: [1]
    Input: head = [1,2,3]                                   // Output: [2,1,3]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    swapPairs(head->next);
    if (head->next != NULL) {
        struct ListNode* temp = NULL;
        temp = head;
        head = head->next;
        temp->next = head->next;
        head->next = temp;
    }
    return head;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    /**
     * Input: head = [1,2,3,4]
     * Output: [2,1,4,3]
     */
    char *listStr = "[1,2]";
    struct ListNode* list = NULL;
    list = buildListFromString(list, listStr);
    
    clock_t start = clock();
    struct ListNode* result = swapPairs(list);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \n");
    printList(list);
    printf("result:\t");
    printList(result);

    printf("\nTime elapsed: %.4f\n", seconds);

    freeList(result);
    return 0;
}
