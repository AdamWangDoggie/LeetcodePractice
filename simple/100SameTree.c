// https://leetcode-cn.com/problems/same-tree/description/
#include <stdbool.h>
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


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q){ return true;}
    if((!p && q) || (p && !q)){return false;}
    if(p->val != q->val){ return false; }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}