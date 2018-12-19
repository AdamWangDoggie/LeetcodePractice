// https://leetcode-cn.com/problems/majority-element-ii/description/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

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

// O(nlogn)
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){ *returnSize = 0; return NULL; }
    int * ret = (int *)malloc(3*sizeof(int));
    int index = 0;
    quick_sort(nums, numsSize);// 先排序
    // 再遍历
    int cur = nums[0], cnt = 1;
    for(int i = 1;i < numsSize; i++){
        if(nums[i] == cur){
            cnt += 1;
            continue;
        }
        else {
            if(cnt > numsSize / 3){
                ret[index++] = cur;
            }
            cnt = 1;
            cur = nums[i];
        }
    }
    if(cnt > numsSize / 3){
        ret[index++] = cur;
    }
    *returnSize = index;
    return ret;
}

// 遍历法 O(n) 同169题, 最多的两个数被其他数给抵消后一定有剩余
int* majorityElement2(int* nums, int numsSize, int* returnSize) {
    int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] == num1) {
            count1++;
        }
        else if(nums[i] == num2) {
            count2++;
        }
        else if(count1 != 0 && count2 != 0){
            count1--;
            count2--;
            
        }
        else if(count1 == 0) {
            num1 = nums[i];
            count1++;
        }
        else if(count2 == 0) {
            num2 = nums[i];
            count2++;
        }
        // printf("num1=%d,num2=%d,count1=%d,count2=%d\n",num1,num2,count1,count2);
    }
    int sum1 = 0, sum2 = 0;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] == num1)
            sum1++;
        if(nums[i] == num2)
            sum2++;
    }
    int *result = NULL;
    int count = 0;
    if(count1 && sum1 > (numsSize / 3)) {
        result = (int*)realloc(result, sizeof(int) *(count + 1));
        result[count++] = num1;
    }
     if(count2 && sum2 > (numsSize / 3)) {
        result = (int*)realloc(result, sizeof(int) *(count + 1));
        result[count++] = num2;
    }
    *returnSize = count;
    return result;
}
