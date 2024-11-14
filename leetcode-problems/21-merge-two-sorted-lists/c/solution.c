/*
    You are given the heads of two sorted linked lists list1 and list2.

    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

    -------------------------
    Topics:
    * Linked List
    * Recursion
    -------------------------
    Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
    -------------------------
    Testcases:
    Input: list1 = [1,2,4], list2 = [1,3,4]                         // Output: [1,1,2,3,4,4]
    Input: list1 = [], list2 = []                                   // Output: []
    Input: list1 = [], list2 = [0]                                  // Output: [0]

*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(struct ListNode* head) {
    while (head->next)
    {
        printf("%d->", head->val);
    }
    printf("\n");
}

struct ListNode* addNode(struct ListNode* head, int val) {

    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (head == NULL) {        
        head->next = newNode;
        newNode->val = val;
        newNode->next = NULL;
    } else {
        return head;
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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    return list1;
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
    printResult(result);
    printf("\n");
    return 0;
}
