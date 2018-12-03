// https://leetcode-cn.com/problems/two-sum/description/

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    // O(n^2)
    // Can reach O(logn) if sort first
    int *ret = (int *)malloc(2*sizeof(int));
    for(int i=0; i< numsSize - 1; i++){
        for(int j = i+1; j < numsSize; j++){
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;    
}