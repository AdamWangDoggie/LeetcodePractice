// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
void pullNums(int* nums, int start, int end){
    for(int i = start; i<end; i++){
        nums[i] = nums[i+1];
    }
}


int removeDuplicates(int* nums, int numsSize) {
    int newSize = numsSize;
    int i = 0;
    while(i < newSize - 1){
        if (nums[i] == nums[i+1]){
            pullNums(nums, i, newSize - 1);
            newSize--;
        } else{
            i++;
        }
    }
    return newSize;
}