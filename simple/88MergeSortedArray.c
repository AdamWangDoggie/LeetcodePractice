// https://leetcode-cn.com/problems/merge-sorted-array/description/
#include <stdio.h>

void pushNums(int* nums, int start, int end){
    for(int i = end; i>start; i--){
        nums[i] = nums[i-1];
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    for(int i=0;i < numsSize; i++){
        if(target<= nums[i]){
            return i;
        }
    }    
    return numsSize;
}

void merge(int* nums1, int m, int* nums2, int n) {
    for(int i = 0; i < n; i++){
        int target = nums2[i]; // 2
        int j = searchInsert(nums1, m+i, target); // 1
        pushNums(nums1, j, m+n-1);
        nums1[j] = target;
    }
}
