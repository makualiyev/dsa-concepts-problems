/**
 * implementation of the algorithm from Hello Algo
 * https://www.hello-algo.com/en/chapter_backtracking/backtracking_algorithm/
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int val)
{
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->val == 7) {
        printf("\tfound it -> %d\n", root->val);
    }
    printf("now -> %d\n", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void preorderTraversalBacktrack(TreeNode *root, int *path, int **result)
{
    if (root == NULL)
        return;

    if (root->val == 7) {
        
        printf("\tfound it -> %d\n", root->val);
    }

    printf("now -> %d\n", root->val);

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void exampleOne(void)
{
    // Example One. Given a binary tree, search and record all nodes with a value of 7, please return a list of nodes.
    TreeNode *root = newNode(1);
    TreeNode *second = newNode(7);
    TreeNode *third = newNode(3);
    TreeNode *fourth = newNode(4);
    TreeNode *fifth = newNode(5);
    TreeNode *sixth = newNode(6);
    TreeNode *seventh = newNode(7);

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    fifth->left = sixth;
    fifth->right = seventh;

    preorderTraversal(root);
}

void exampleTwo(void)
{
    // Example Two. In a binary tree, search for all nodes with a value of 7 and please return the paths from the root node to these nodes.
    TreeNode *root = newNode(1);
    TreeNode *second = newNode(7);
    TreeNode *third = newNode(3);
    TreeNode *fourth = newNode(4);
    TreeNode *fifth = newNode(5);
    TreeNode *sixth = newNode(6);
    TreeNode *seventh = newNode(7);

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    fifth->left = sixth;
    fifth->right = seventh;

    int **result;
    int *path = (int *)malloc(sizeof(int) * 10);
    preorderTraversalBacktrack(root, path, result);
}

int main(int argc, char *argv[])
{
    exampleTwo();
    return 0;
}
