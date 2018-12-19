// https://leetcode-cn.com/problems/majority-element/description/
#include <stdlib.h>
#include <stdio.h>

void traversal(int *nums, int n){
    for(int t = 0; t < n; t++){
        printf("%d ", nums[t]);
    }
    printf("\n");
}

void swap(int *nums, int a, int b){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int partition(int *nums, int numsSize){
    int p = nums[numsSize - 1];
    int i = -1, j = 0;
    while(j < numsSize -1){
        if(nums[j] < p){
            swap(nums, i+1, j);
            i++; j++;
        } else{ j++; }
    }
    swap(nums, i+1, numsSize - 1);
    return i+1;
}

void quick_sort(int *nums, int numsSize){
    if(numsSize <= 1){ return; }
    int i = partition(nums, numsSize);
    quick_sort(nums, i);
    quick_sort(nums + i + 1, numsSize - i - 1);
}

// 先排序再遍历 O(nlogn)
int majorityElement(int* nums, int numsSize) {
    if(numsSize < 1){ return NULL;}
    if(numsSize == 1){ return nums[0]; }
    quick_sort(nums, numsSize);
    int cur = nums[0], cnt = 1;
    for(int i = 1;i < numsSize; i++){
        if(cnt > numsSize/2){ 
            return cur;
        }
        if(nums[i] == cur){
            cnt += 1;
            continue;
        }
        else {
            cnt = 1;
            cur = nums[i];
        }
    }
    return cur;
}

// 因为此题对众数的定义是大于n/2个, 故其与非众数一换一全部抵消后, 仍剩下的就是要找的众数
// O(n)
int majorityElement2(int* nums, int numsSize) 
{
    int cur,count = 0;
    for(int i = 0;i < numsSize;i++)
    {
        if(count == 0)
        {
            cur = nums[i];
            count = 1;
        }
        else{
            if(cur == nums[i])
                count++;
            else count--;
        }
    }
    return cur;
}