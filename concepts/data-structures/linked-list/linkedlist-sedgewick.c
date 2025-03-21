/**
 * Sedgewick R. Algorithms in C
 * Implementation
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};

struct node *head, *z, *t;

void listinitialize(void)
{
    head = (struct node *)malloc(sizeof(*head));
    z = (struct node *)malloc(sizeof(*z));
    head->next = z;
    z->next = z;
}

void deletenext(struct node *t)
{
    t->next = t->next->next;
}

struct node *insertafter(int v, struct node *t)
{
    struct node *x;
    x = (struct node *)malloc(sizeof(*x));
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

void printlist(struct node *head)
{
    if (head == NULL) {
        return;
    }
    printf("->%d", head->key);
    head = head->next;
}


int main(int argc, char *argv[])
{
    listinitialize();
    head = insertafter(1, head);
    printlist(head);
    return 0;
}