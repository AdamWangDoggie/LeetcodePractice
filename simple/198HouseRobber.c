// https://leetcode-cn.com/problems/house-robber/description/

// DP
int rob_do(int* nums, int*res, int numsSize) {
    if(res[numsSize-1] >= 0){
        return res[numsSize-1];
    }
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2){
        return nums[0]> nums[1]?nums[0]:nums[1];
    }
    if( numsSize == 3){
        int take02 = nums[0] + nums[2];
        int take1 = nums[1];
        return take02 > take1 ? take02 : take1;
    }
    int take = nums[numsSize - 1] + rob_do(nums, res, numsSize - 2);
    int untake = rob_do(nums, res, numsSize - 1);
    int result =  take >  untake ? take : untake;
    res[numsSize - 1] = result;
    return  result;
}

int rob(int *nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }
    int res[numsSize];
    for (int k = 0; k<numsSize; k++){
        res[k] = -1;
    }
    return rob_do(nums, res, numsSize);

}