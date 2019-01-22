// 二叉树的最近公共祖先
// 简单递归, 要么都在左边, 要么都在右边, 不然直接返回根结点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdlib.h>
#include <stdbool.h>

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ( root == NULL || root==p || root == q )
        return root;
    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);
    
    if ( left == NULL )
        return right;
    if ( right == NULL )
        return left;
    return root;
}
