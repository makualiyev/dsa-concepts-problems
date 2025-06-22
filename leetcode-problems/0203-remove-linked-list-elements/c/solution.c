/*
    Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, 
    and return the new head.

    -------------------------
    Topics:
    * Linked List
    * Recursion
    -------------------------
    Constraints:
    The number of nodes in the list is in the range [0, 10^4].
    1 <= Node.val <= 50
    0 <= val <= 50
    -------------------------
    Testcases:
    Input: head = [1,2,6,3,4,5,6], val = 6                          // Output: [1,2,3,4,5]
    Input: head = [], val = 1                                       // Output: []
    Input: head = [7,7,7,7], val = 7                                // Output: []

*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* head) {
    struct ListNode* node = head;
    
    while (1) {
        if (node == NULL)
            break;
        printf("->%d", node->val);
        node = node->next;
    }
    printf("\n");

    free(node);
}

struct ListNode* addNode(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (head == NULL) {
        head = newNode;
        newNode->next = NULL;
        newNode->val = val;
    } else {
        newNode->val = val;
        newNode->next = head;
        (newNode->next)->next = NULL;
        head = newNode;
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    return head;
}

int main(int argc, char *argv[])
{
    // Input: list1 = [1,2,4], list2 = [1,3,4]
    // Output: [1,1,2,3,4,4]
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    list1 = addNode(list1, 1);
    list1 = addNode(list1, 2);
    list1 = addNode(list1, 4);
    list2 = addNode(list2, 1);
    list2 = addNode(list2, 3);
    list2 = addNode(list2, 4);

    struct ListNode* result = mergeTwoLists(list1, list2);
    printf("\n======================\n");
    printf("testCase\n\tn: %d\n======================\nresult:\t", 1);
    printList(result);
    printf("\n");
    return 0;
}
