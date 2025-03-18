/*
    Given the head of a linked list, remove the nth node from the end of the
    list and return its head.

    -------------------------
    Topics:
    * Linked List
    * Two Pointers
    -------------------------
    Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
    -------------------------
    Testcases:
    Input: head = [1,2,3,4,5], n = 2                // Output: [1,2,3,5]
    Input: head = [1], n = 1                        // Output: []
    Input: head = [1,2], n = 1                      // Output: [1]
    
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printList(const struct ListNode* head)
{
    struct ListNode* p = head;
    while (p != NULL) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("\n");
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    return head;    
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");

    struct ListNode* head = NULL;
    struct ListNode* h = malloc(sizeof(*h));
    h->val = 5;
    h->next = NULL;
    head = h;
    int n = 2;

    clock_t start = clock();
    int** result = removeNthFromEnd(head, n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("======================\n");
    printf("testCase: \n");
    
    printList(head);

    printf("result:\t");
    
    printList(head);
    
    free(h);
    
    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
