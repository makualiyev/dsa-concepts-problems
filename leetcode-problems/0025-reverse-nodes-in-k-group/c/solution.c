/*
    Given the head of a linked list, reverse the nodes of the list k at a time,
    and return the modified list.
    
    k is a positive integer and is less than or equal to the length of the linked
    list. If the number of nodes is not a multiple of k then left-out nodes, in
    the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may
    be changed.

    Follow-up: Can you solve the problem in O(1) extra memory space?

    -------------------------
    Topics:
    * Linked List
    * Recursion
    -------------------------
    Constraints:
    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000
    -------------------------
    Testcases:
    Input: head = [1,2,3,4,5], k = 2                        Output: [2,1,4,3,5]
    Input: head = head = [1,2,3,4,5], k = 3                 Output: [3,2,1,4,5]

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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    return head;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    int k = 2;
    char *listStr = "[1,2,3,4,5]";
    struct ListNode* list = NULL;
    list = buildListFromString(list, listStr);
    
    clock_t start = clock();
    struct ListNode* result = reverseKGroup(list, k);
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
