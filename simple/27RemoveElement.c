// https://leetcode-cn.com/problems/remove-element/description/

void pullNums(int* nums, int start, int end){
    for(int i = start; i<end; i++){
        nums[i] = nums[i+1];
    }
}


int removeElement(int* nums, int numsSize, int val) {
    int i = 0, newSize = numsSize;
    while(i < newSize){
        if(nums[i]==val){
            pullNums(nums, i, newSize - 1);
            newSize--;
        } else{
            i++;
        }
    }
    return newSize;
}