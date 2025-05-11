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

/**
 * examples from CS 112
 * https://www.cs.bu.edu/fac/snyder/cs112/CourseMaterials/LinkedListNotes.Recursion.html
 * 
*/

struct ListNode* construct(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    else {
        head->next = construct(head->next);
        return head;
    }
}

struct ListNode* addOne(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    else {
        head->next = addOne(head->next);
        ++head->val;
        return head;
    }
}

struct ListNode *copy(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    else {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = head->val;
        newNode->next = copy(head->next);
        return newNode;
    }
}

/**
 * examples from 'mycodeschool'
 * https://www.youtube.com/@mycodeschool
 */
void insertAtNthNode(struct ListNode* head, int val, int n)
{
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    if (n == 1) {
        /**
         * check the behavior here, if I pass the pointer
         * to the list (pointer to a pointer `head`), then
         * it passes, but not if we pass a pointer as a pointer
         */
        // wrong
        temp->next = head;
        head = temp;
        return;

        // right
        // temp->next = *head;
        // *head = temp;
        // return;
    }
    // wrong
    struct ListNode *tempp = head;
    // right?
    // struct ListNode *tempp = *head;
    for (int i = 0; i < n - 2; i++) {
        tempp = tempp->next;
    }
    temp->next = tempp->next;
    tempp->next = temp;
}

int main(int argc, char *argv[])
{
    printf("METAINFO:\targv:[%s] argc:[%d]\n", argv[0], argc);
    printf("======================\n");
    
    char *listStr = "[1,2,3,4,5]";
    struct ListNode* list = NULL;
    list = buildListFromString(list, listStr);

    // struct ListNode *newList = copy(list);

    printf("list: ");
    printList(list);

    insertAtNthNode(list, 22, 1);
    printList(list);
    // printf("new list: ");
    // printList(newList);
    // printf("list : %p\tnewlist : %p\n", (void *)list, (void *)newList);




    freeList(list);
    // freeList(newList);
    return 0;
}