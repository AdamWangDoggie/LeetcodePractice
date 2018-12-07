// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/

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
 
int maxDepth(struct TreeNode* root) {
    if(!root){return 0;}
    int ld = maxDepth(root->left), rd = maxDepth(root->right);
    if(ld>rd){ return ld+1;} else { return rd + 1;}

}