#include <stdio.h>
#include <stdlib.h>


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

void printListRecur(struct ListNode* head)
{
    if (head == NULL){
        return;
    }
    printf("->%d", head->val);
    printListRecur(head->next);
}

struct ListNode* reverseListRecur(struct ListNode* head)
{
    if (head == NULL) {
        return head;
    }
    reverseListRecur(head->next);
    // struct ListNode* newHead = (struct ListNode*)malloc(sizeof(*newHead));
    return head;
}

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* temp;
    struct ListNode* reversed = (struct ListNode*)malloc(sizeof(*reversed));
    temp = head;

    while (temp != NULL) {
        temp = temp->next;
    }
    
    return head;
}



int main(int argc, char *argv[])
{
    struct ListNode *head = NULL;
    struct ListNode *headRev = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);

    printListRecur(head);
    headRev = reverseListRecur(head);
    printf("\n");
    printListRecur(headRev);
    printf("\n");

    return 0;
}