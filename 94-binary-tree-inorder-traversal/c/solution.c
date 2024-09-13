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

struct TreeNode *makeTree(int *rootArr, int *rootArrSize)
{
    printf("size of arraY:%d\n", *rootArrSize);
    if (*rootArrSize == 0)
    {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root = NULL;
        return root;
    }
    
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->right = NULL;
    root->left = NULL;
    return root;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    return returnSize;
}


int main(int argc, char *argv[])
{
    //  [1,null,2,3]
    int rootArr[] = { 1, 2, 3 };
    int rootArrSize = (int)(sizeof(rootArr) / sizeof(int));
    struct TreeNode* root = makeTree(rootArr, &rootArrSize);

    

    // int *result = inorderTraversal(root, &returnSize);

    return 0;
}
