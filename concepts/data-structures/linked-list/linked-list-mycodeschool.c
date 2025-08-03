/**
 * Implementation by `mycodeschool`
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node)
{
    struct Node * temp = node;

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// void Reverse()
// {
//     struct Node *current, *prev, *next;
//     prev = NULL;
//     current = head;
    
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
// }

void RecReverse(struct Node** head, struct Node* p)
{
    if (p->next == NULL) {
        *head = p;
        return;
    }
    RecReverse(head, p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void swapNodes(struct Node** head, struct Node* p, int pos)
{
    if (p->next == NULL) {
        printf("\tDEBUG pos:%d\n", pos);
        return;
    }
    printf("\tnoDEBUG pos:%d\n", pos);
    pos++;
    swapNodes(head, p->next, pos);

    // if (pos % 2 != 0) {
    //     struct Node* q = p->next;
    //     q->next = p;
    //     p->next = NULL;
    // }

    printf("\t\tDEBUG pos:%d\tdata:%d\n", pos, p->data);
}

int main(int argc, char *argv[])
{
    struct Node *head;
    struct Node* second = malloc(sizeof(*second));
    struct Node* third = malloc(sizeof(*third));
    struct Node* fourth = malloc(sizeof(*fourth));
    struct Node* fifth = malloc(sizeof(*fifth));

    second->data = 1;
    second->next = third;
    third->data = 2;
    third->next = fourth;
    fourth->data = 3;
    fourth->next = fifth;
    fifth->data = 4;
    fifth->next = NULL;
    head = second;

    printList(head);
    // Reverse();
    swapNodes(&head, head, 0);
    printf("\t---------\n");
    printList(head);

    
    return 0;
}