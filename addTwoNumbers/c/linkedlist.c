/*
Singly Linked List implementation in C from Youtube
channel "Low Level Programming" with menu list for
actions.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
} Node;

Node* head = NULL;

void printLinkedList()
{
    Node* node = malloc(sizeof(Node));
    node = head;

    while (node != NULL) {
        printf("%d", node->data);
        printf("->");
        node = node->link;
    }
    printf("->\n");

}

void addElementToLinkedList(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    if (head == NULL) {
        node->link = NULL;
    } else {
        node->link = head;
    }
    head = node;
}

void printMenu(void)
{
    printf("Choose an option:\n"
           "1. Print the linked list.\n"
           "2. Add a node to the linked list.\n"
           "3. Delete a node from the linked list.\n"
           "4. Exit.\n");
}

int main(int argc, char *argv[])
{
    int a, d;

    printMenu();
    
    while (a != 4) {
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                printLinkedList();
                printMenu();
                break;
            case 2:
                printf("Type a number to add:");
                scanf("%d", &d);
                addElementToLinkedList(d);
                printMenu();
                break;
            case 3:
                printf("Under construction...\n");
                printMenu();
                break;
            case 4:
                printf("Exiting program.");
                break;
        }
    }

    return 0;
}