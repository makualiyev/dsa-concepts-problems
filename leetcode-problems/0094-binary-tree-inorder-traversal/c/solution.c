/*
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    -------------------------
    Topics:
    * Stack
    * Tree
    * Depth-First Search
    * Binary Tree
    * 
    -------------------------
    Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
    -------------------------
    Testcases:
    Input: root = [1,null,2,3]                                      // Output: [1,3,2]
    Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]                // Output: [4,2,6,5,7,1,3,9,8]
    Input: root = []                                                // Output: []
    Input: root = [1]                                               // Output: [1]

    -------------------------
    Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printTree(struct TreeNode *root, int *nodeSize, int *arr)
{
    if (root == NULL)
    {
        return;
    } 
    printTree(root->left, nodeSize, arr);
    printf("%d ", root->val);
    printTree(root->right, nodeSize, arr);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *arr = (int *)malloc(sizeof(int));
    if (arr == NULL)
    {
        printf("Memory is not allocated!");
        exit(30);
    }
    printTree(root, returnSize, arr);
    return arr;
}

int main(int argc, char *argv[])
{
    //  [1,null,2,3]
    struct TreeNode *root = newNode(1);
    struct TreeNode *second = newNode(2);
    struct TreeNode *third = newNode(3);
    struct TreeNode *fourth = newNode(4);
    struct TreeNode *fifth = newNode(5);
    struct TreeNode *sixth = newNode(6);
    struct TreeNode *seventh = newNode(7);
    struct TreeNode *eighth = newNode(8);
    struct TreeNode *ninth = newNode(9);

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    fifth->left = sixth;
    fifth->right = seventh;
    third->right = eighth;
    eighth->left = ninth;

    int arrSize = 0;
    int *arr;

    arr = inorderTraversal(root, &arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }

    free(root);

    return 0;
}
