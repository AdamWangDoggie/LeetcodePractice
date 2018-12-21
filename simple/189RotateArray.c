// https://leetcode-cn.com/problems/rotate-array/


// by move, O(kn) -> O(n^2)
void h(int* nums, int numsSize){
    int tmp = nums[numsSize - 1];
    for(int i = numsSize - 1; i>0 ; i--){
        nums[i] = nums[i-1];
    }
    nums[0] = tmp;
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    for(int i = 0; i<k; i++){
        h(nums, numsSize);
    }
}


// by reverse O(n)
void reverse(int* num,int first,int last)
{
    int temp;
    while(first < last)
    {
        temp = num[first];
        num[first] = num [last];
        num[last] = temp;
        first++;
        last--;
    }
}
void rotate2(int* nums, int numsSize, int k) {
    k = k % numsSize;
    reverse(nums,0,numsSize - k - 1);
    reverse(nums,numsSize - k,numsSize - 1);
    reverse(nums,0,numsSize - 1);
}