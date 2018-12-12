// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 有序数组转化为高度平衡二叉搜索树, 因为已经有序, 所以BST不难, 用二分递归可保证高度平衡

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) { return NULL; }
    if (numsSize == 1) { 
        struct TreeNode * ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        ret->val = nums[0];
        ret->left = NULL;
        ret->right = NULL;
        return ret; 
    }

    int mid = numsSize / 2;
    struct TreeNode * ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ret->val = nums[mid];
    int leftSize = mid; int rightSize = numsSize - mid - 1;
    ret->left = sortedArrayToBST(nums, leftSize);
    ret->right = sortedArrayToBST(nums+mid+1, rightSize);

    return ret;
}