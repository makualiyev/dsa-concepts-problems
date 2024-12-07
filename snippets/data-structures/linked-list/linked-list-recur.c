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
    /**
     * here we have `head` - which is let's say (4)->(NULL)
     * and `newHead` which is (NULL) i.e. (4)->next. Thus
     * now we have two successive nodes (4)->(NULL) for last
     * function call stack. So, for next one it would be
     * `head` (3)->(4) `newHead` (4)->(NULL)
     * or
     * `head` (3) `newHead` (4)
     * Then the solution lies in reversing the link from (4)
     * to (
     */
    if (head == NULL) {
        return head;
    }

    struct ListNode* newHead = reverseListRecur(head->next);
    if (head->next == NULL) {
        return head;
    } 

    struct ListNode* temp1;
    struct ListNode* temp2;
    temp1 = newHead;
    temp2 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp2->next = NULL;
    temp1->next = temp2;
    
    return newHead;
}

void reverseListRecurNoret(struct ListNode* head)
{
    /**
     * here we have `head` - which is let's say (4)->(NULL)
     * and `newHead` which is (NULL) i.e. (4)->next. Thus
     * now we have two successive nodes (4)->(NULL) for last
     * function call stack. So, for next one it would be
     * `head` (3)->(4) `newHead` (4)->(NULL)
     * or
     * `head` (3) `newHead` (4)
     * Then the solution lies in reversing the link from (4)
     * to (
     */
    if (head == NULL) {
        return;
    }

    reverseListRecurNoret(head->next);
    
    struct ListNode* newHead;
    if (head->next == NULL) {
        newHead = head;
    } else {
        printf("newHead\t%d\n", newHead->val);
        struct ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }


    }

}



int main(int argc, char *argv[])
{
    struct ListNode *head = NULL;
    // struct ListNode *headRev = NULL;
    head = addNode(head, 1);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 4);

    printListRecur(head);
    reverseListRecurNoret(head);
    printf("\n");
    // printListRecur(headRev);
    // printf("\n");
    // printf("\n");
    printListRecur(head);
    printf("\n");

    return 0;
}