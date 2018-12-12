// https://leetcode-cn.com/problems/path-sum/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode * node, int value){
    if(!node){ return false; }// 探底, 返回false
    if(node->val == value && !node->left && !node->right){ return true; }// 叶子结点, 且和相等, 返回true
    return helper(node->left, value - node->val) || helper(node->right, value - node->val);
}


bool hasPathSum(struct TreeNode* root, int sum) {
    return helper(root, sum);
}