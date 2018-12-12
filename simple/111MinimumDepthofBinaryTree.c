// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 因为最小深度要区分是否叶子结点, 所以这里的逻辑略显复杂
int minDepth(struct TreeNode* root) {
    if(!root){return 0; }
    int l = INT_MAX, r = INT_MAX;

    if(root->left){ l = minDepth(root->left); }
    if(root->right){ r = minDepth(root->right); }
    if(l < INT_MAX && r == INT_MAX){
        return l + 1;
    }
    if(l == INT_MAX && r < INT_MAX){
        return r + 1;
    }
    if(l < INT_MAX && r < INT_MAX){
        int min;
        if(l < r){min = l;}else{min=r;}
        return min + 1;
    }
    return 1;
}

int main(){
    struct TreeNode left = {2, NULL,NULL};
    struct TreeNode root = {1, NULL, &left};

    int ret = minDepth(&root);
    return 1;
}