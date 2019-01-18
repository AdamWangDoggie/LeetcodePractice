int findLengthOfLCIS(int* nums, int numsSize) {
    if(numsSize == 0){return 0;}
    int cur = nums[0], tmp = 1, ret = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > cur){
            tmp++;
        }
        else{
            tmp = 1;
        }
        cur = nums[i];
        if(tmp > ret){ret = tmp;}
    }
    return ret;
}