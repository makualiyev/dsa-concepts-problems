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

void printList(struct ListNode* head) {
    struct ListNode* node = head;
    while (node != NULL) {
        printf("%d->", node->val);
        node = node->next;
    }
    printf("\n");
}

int measureList(struct ListNode* head) {
    struct ListNode* p = head;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

struct ListNode* addNodeReversed(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
        newNode->val = val;
    } else {
        newNode->next = head;
        newNode->val = val;
        head = newNode;
    }
    return head;
}

struct ListNode* addNode(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = head;

    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
        newNode->val = val;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = newNode;
        newNode->val = val;
        newNode->next = NULL;
    }
    return head;
}

struct ListNode* swapPairs(struct ListNode* head) {
    // split(head);
    // split list into two
    // then swap
    int len = measureList(head);
    int mid = (len / 2) + (len % 2);
    // splitList(head, mid);
    return head;
}

int main(int argc, char *argv[])
{
    // Input: head = [1,2,3,4]
    // Output: [2,1,4,3]
    struct ListNode* list1 = NULL;
    list1 = addNode(list1, 1);
    list1 = addNode(list1, 2);
    list1 = addNode(list1, 3);
    list1 = addNode(list1, 4);

    struct ListNode* result = swapPairs(list1);
    printf("\n======================\n");
    printf("testCase\n\tn: %s\n======================\nresult:\t", "1->2->3->4");
    printList(result);
    printf("\n");
    free(result);
    return 0;
}
