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
    struct ListNode* temp = head;
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d->", temp->val);
    printList(head->next);
}

struct ListNode* constructFromString(char *listStr)
{
    struct ListNode* head = NULL;
    return head;
}

struct ListNode* swapPairs(struct ListNode* head) {
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
    char *listStr = "1->2->3->4->";
    struct ListNode* list = constructFromString(listStr);
    
    clock_t start = clock();
    struct ListNode* result = swapPairs(list);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: %s\n", "1->2->3->4");
    printf("result:\t");
    printList(result);
    printf("\nTime elapsed: %.4f\n", seconds);

    // free(list);
    free(result);
    return 0;
}
