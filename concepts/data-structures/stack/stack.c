#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};

static struct *head, *z, *t;

void stackinit()
{
    head = (struct node*)malloc(sizeof(*head));
    z = (struct node*)malloc(sizeof(*z));
    head->next = z;
    head->key = 0;
    z->next = z;
}

int main(int argc, char* argv[])
{
    return 0;
}