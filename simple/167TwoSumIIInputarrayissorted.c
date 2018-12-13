// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

// 因为是有序数组, 向中间靠拢即可
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int * ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0, j = numbersSize - 1, num = 0;
    while(i<j){
        num = numbers[i] + numbers[j];
        if( num == target){
            ret[0] = i+1; ret[1] = j+1; break; 
        }
        else if(num < target){
            i++;
        }else {
            j--;
        }
    }
    
    return ret;
}