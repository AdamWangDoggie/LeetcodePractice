// https://leetcode-cn.com/problems/balanced-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 三元表达式效率这么高???这样改了下击败100%?
int max(a, b){ return a>b?a:b;}

int maxDepth(struct TreeNode* root) {
    if(!root){return 0;}
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

bool isBalanced(struct TreeNode* root) {
    if(!root){return true;}
    if(!root->left && !root->right){return true;}
    return isBalanced(root->left) && isBalanced(root->right) &&
    abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
}
