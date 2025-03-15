/**
 * Implementation by `mycodeschool`
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* Insert(struct Node* head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(*temp));
    temp->data = x;
    temp->next = NULL;
    

    if (head != NULL) {
        temp->next = head;
    }
    head = temp;
    return head;
}

void insertAtNth(int data, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(*temp1));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node* temp2 = head;
    for (int i = 0; i < n - 2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    head = NULL;
    insertAtNth(2, 1);
    insertAtNth(3, 2);
    insertAtNth(4, 1);
    insertAtNth(5, 2);
    Print();
    return 0;
}