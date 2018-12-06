// https://leetcode-cn.com/problems/maximum-subarray/description/
#include <limits.h>
#include <stdio.h>

int maxMidSubArray(int * nums, int mid, int numsSize){
    int maxSumLeft = INT_MIN, maxSumRight = INT_MIN;
    int sumLeft = 0, sumRight = 0;
    // 因此处mid最小也是1, 所以让左边不含中点, 以免右边出界
    for(int i = mid-1; i>=0; i--){ // 不含中点, 向左延伸
        sumLeft += nums[i];
        if (sumLeft > maxSumLeft){
            maxSumLeft = sumLeft;
        }
    }
    for(int j = mid; j<numsSize; j++){  // 含中点, 向右延伸
        sumRight += nums[j];
        if(sumRight > maxSumRight){
            maxSumRight = sumRight;
        }
    }
    int ret = maxSumLeft + maxSumRight;
    return ret;
}

int maxSubArray(int* nums, int numsSize) {
    // 最大连续子数组, 分为两种情况, 跨中点的最大子数组和不跨中点的最大子数组
    // 不跨中点的最大子数组即左半数组, 右半数组
    // O(nlogn)
    if (numsSize<=1){ return nums[0]; }
    int mid = numsSize / 2;

    int leftSum = maxSubArray(nums, mid);
    int rightSum = maxSubArray(nums + mid, numsSize - mid);
    int midSum = maxMidSubArray(nums, mid, numsSize);
    int ret = leftSum;
    if(rightSum > ret){
        ret = rightSum;
    }
    if(midSum > ret){
        ret = midSum;
    }
    return ret;
}


int maxSubArrayTwo(int *nums, int numsSize){
    // 第二种O(n)解法, 只需遍历一次
    if(numsSize<=1){
        return nums[0];
    }
    int nowSum = 0, maxSum = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        nowSum += nums[i];
        if(nowSum > maxSum){ // 若比最大值更大, 则更新最大值
            maxSum = nowSum;
        }
        // 若当前子数组和小于0, 那么当前子数组对最终最大子数组的贡献是负面的, 那么最大子数组一定不会包含这段子数组, 除非后面的元素都是更小的负数, 
        // 此思路基于“连续”这个条件, 试想, 最大子数组中, 某一段的和为负数, 那么不包含它的话和当然更大
        if(nowSum < 0){
            nowSum = 0;
        }
    }
    return maxSum;
}

int main(){
    int me[2] = {-2, 1};
    int ret = maxSubArrayTwo(me, 2);
    printf("final: %d\n", ret);
    return 1;
}