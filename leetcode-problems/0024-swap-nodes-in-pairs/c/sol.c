#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

void printList(struct ListNode* head)
{
    struct ListNode* temp = head;
    while (temp) {
        printf("->%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(struct ListNode* head, struct ListNode* prev)
{
    if (head == NULL) {
        printf("\tDEBUG: stopped\n");
        return;
    }
    struct ListNode* prev = head;
    head = head->next;
    reverseList(head, prev);
    // if (head->next == NULL) {
    //     return;
    // }
    prev->next = head->next;
    head->next = prev;
    prev = head;
}

int main(int argc, char *argv[])
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* second = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* third = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* fourth = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = fourth;

    fourth->val = 4;
    fourth->next = NULL;
    
    printList(head);
    printf("\t------------\n");
    
    reverseList(head, NULL);

    printList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);
    
    return 0;
}