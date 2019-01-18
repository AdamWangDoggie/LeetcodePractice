// 数组中第K大的数, 
/*
1. 若确保所有元素都不相同, 可以partition到k即可, 效率较快速排序略快
2. 若存在相同元素, partition可能无法处理, 直接排序后返回即可.
*/
#include <stdlib.h>

void swap(int *nums, int a, int b){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int partition(int *nums, int start, int end){
    int p = nums[end];
    int i = -1, j = 0;
    while(j <= end){
        if(nums[j] > p){
            swap(nums, i+1, j);
            i++; j++;
        } else{ j++; }
    }
    swap(nums, i+1, end);
    return i+1;
}

int find(int* nums, int start, int end, int target_index){
    if(start == end){
        return nums[start];
    }
    int i = partition(nums, start, end);
    if(i == target_index){
        return nums[i];
    } else if (i > target_index){
        return find(nums, start, i - 1, target_index);
    } else {
        return find(nums, i + 1, end, target_index);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return find(nums, 0, numsSize - 1, k - 1);
}

int main(){
    int nums[8] = {3, 3, 3, 3, 3, 3, 3, 3};
    int ret = findKthLargest(nums, 8, 1);
    return 1;


}