#include <stdio.h>
#include <stdlib.h>


typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createNode(int value) {
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }

}

void printTreeRec(treenode *root, int level)
{
    if (root == NULL) {
        printTabs(level);
        printf("---<empty>---\n");
        return;
    }
    printTabs(level);
    printf("value = %d\n", root->value);
    printTabs(level);
    printf("left\n");

    printTreeRec(root->left, level + 1);
    printTabs(level);
    printf("right\n");

    printTabs(level);
    printTreeRec(root->right, level + 1);
    printf("done");
    return;
}

void printTree(treenode *root) {
    printTreeRec(root, 0);
}


int main (int argc, char *argv[])
{
    treenode *n1 = createNode(10);
    treenode *n2 = createNode(11);
    treenode *n3 = createNode(12);
    treenode *n4 = createNode(13);
    treenode *n5 = createNode(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}