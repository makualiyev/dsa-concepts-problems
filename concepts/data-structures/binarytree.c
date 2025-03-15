#include <stdio.h>
#include <stdlib.h>

/** Node, the basic data structure in the tree */
struct TreeNode {
    char* data;
    struct TreeNode *right;
    struct TreeNode *left;
};

/** The node constructor, which receives the key value input and returns a node
 * pointer
 * @param data data to store in a new node
 * @returns new node with the provided data
 * @note the node must be deleted before program terminates to avoid memory
 * leaks
 */
struct TreeNode *newNode(char* data)
{
    // creates a slug
    struct TreeNode *tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    // initializes the slug
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

/**
 * Prints tree data structure
 * preorder?
 * @param root root Tree Node
 * @returns void
 */
void printTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("<-empty->");
        return;
    }
    printf("%s", root->data);

}


int main (int argc, char *argv[])
{
    struct TreeNode *root = NULL;
    root = newNode("A");
    root->left = newNode("B");
    root->right = newNode("C");

    printTree(root);

    return 0;
}