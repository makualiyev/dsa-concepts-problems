/*
    Given the head of a singly linked list and two integers left and right
    where left <= right, reverse the nodes of the list from position left
    to position right, and return the reversed list.

    -------------------------
    Topics:
    * Linked List
    -------------------------
    Constraints:
    * The number of nodes in the list is n.
    * 1 <= n <= 500
    * -500 <= Node.val <= 500
    * 1 <= left <= right <= n
    -------------------------
    Testcases:
    Input: head = [1,2,3,4,5], left = 2, right = 4          Output: [1,4,3,2,5]
    Input: head = head = [5], left = 1, right = 1           Output: [5]

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

void reverseNode(struct ListNode** head, struct ListNode* node)
{
    if (node->next == NULL) {
        *head = node;
        return;
    }
    reverseNode(head, node->next);
    struct ListNode* next = node->next;
    next->next = node;
    node->next = NULL;
}

void reverseNodeIteratively(struct ListNode **head, struct ListNode *node)
{
    struct ListNode *temp = node;
    struct ListNode *prev = NULL, *curr = temp, *fnext = temp->next;
    
    while (temp != NULL) {
        curr->next = prev;

        if (fnext == NULL) {
            *head = curr;
            return;
        }
        temp = fnext;
        prev = curr;
        curr = temp;
        fnext = curr->next;
    }
}

void reverseNodeRecursively(struct ListNode **head, struct ListNode *node)
{
    if (node == NULL || node->next == NULL) {
        *head = node;
        return;
    }
    reverseNodeRecursively(head, node->next);
    struct ListNode *pnext = node->next;
    pnext->next = node;
    node->next = NULL;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode *temp = head, *prev = NULL, *leftAnchor = NULL, *rightAnchor = NULL;
    int pos = 1;
    if (left == right) {
        return head;
    }

    while (temp != NULL) {
        if (pos == left - 1) {
            leftAnchor = temp;
        } else if (pos == right + 1) {
            rightAnchor = temp;
            prev->next = NULL;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }
    if (leftAnchor == NULL) {
        reverseNodeIteratively(&(head), head);
    } else {
        reverseNodeIteratively(&(leftAnchor->next), leftAnchor->next);
    }
    
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = rightAnchor;

    return head;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    
    int left = 2;
    int right = 4;
    char *listStr = "[1,2,3,4,5]";
    
    struct ListNode* list = NULL;
    list = buildListFromString(list, listStr);
    
    clock_t start = clock();
    struct ListNode* result = reverseBetween(list, left, right);
    // reverseNodeRecursively(&list, list);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \n\t");
    printf("left: %d\n\tright: %d\n\t", left, right);
    printList(list);
    printf("result: \n\t");
    printList(result);
    // printList(list);

    printf("\nTime elapsed: %.4f\n", seconds);

    freeList(result);
    // freeList(list);
    return 0;
}
