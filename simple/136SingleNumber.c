// https://leetcode-cn.com/problems/single-number/description/

int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for(int i=0; i<numsSize; i++){
        // 异或: a 和 b 中不同的位 置为1, 
        ret ^= nums[i];
    }
    return ret;
}