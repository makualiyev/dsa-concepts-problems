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
#include <string.h>
#include <math.h>
#include <time.h>

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

void freeList(struct ListNode* head)
{
    if (head == NULL)
        return;
    freeList(head->next);
    free(head);
}

size_t listLen(struct ListNode* head)
{
    size_t len = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

struct ListNode* addNodeReversed(struct ListNode* head, int val)
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

struct ListNode* buildListFromString(struct ListNode* head, char* string)
{
    // [12,3]
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    int target = (int)listLen(head) - n;

    struct ListNode* temp = head;
    struct ListNode* freedNode;
    // printf("\t\tlen:%d\n", (int)listLen(head));
    // printf("\t\ttarget:%d\n", target);

    if (target == 0) {
        head = head->next;
        free(temp);
        return head;
    }

    while (temp != NULL) {
        if (i == target - 1) {
            // printf("DEBUG\ttemp->next: %d temp->next- >next: %d\n", (temp->next)->val, (temp->next)? 0: ((temp->next)->next)->val);
            freedNode = temp->next;
            temp->next = (temp->next)->next;
        }
        temp = temp->next;
        i++;
    }
    free(freedNode);
    return head;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    char* str = "[1]";
    struct ListNode* head = NULL;
    head = buildListFromString(head, str);
    int n = 1;

    printf("======================\n");
    printf("testCase: \n");
    printf("n= %d \t|\t", n);
    printList(head);

    clock_t start = clock();
    struct ListNode* result = removeNthFromEnd(head, n);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("result:\t");
    printList(result);
    
    freeList(result);
    printf("\nTime elapsed: %.4f\n", seconds);
    return 0;
}
