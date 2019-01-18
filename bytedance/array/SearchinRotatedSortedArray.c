// 搜索旋转排序数组, 要求时间复杂度O(logn)
/*
1. 二分找到旋转点
2. 二分查找
O(2logn)
*/

int bin_detect(int* nums, int start, int end){
    if(start == end){
        return start;
    }
    int mid = (start + end) / 2;
    if(nums[mid] > nums[end]){
        return bin_detect(nums, mid + 1, end);
    } else {
        return bin_detect(nums, 0, mid);
    }
}

int bin_search(int* nums, int start, int end, int target){
    if(start > end){
        return -1;
    }
    int mid = (start + end) / 2;
    if(target == nums[mid]){
        return mid;
    } else {
        if(start == end){ return -1; }
        else if(target > nums[mid]){
            return bin_search(nums, mid+1, end, target);
        }else{
            return bin_search(nums, start, mid, target);
        }
    }
}

int search(int* nums, int numsSize, int target) {
    if(numsSize == 0){ return -1; }
    int rotated_at = bin_detect(nums, 0, numsSize - 1);
    // rotated_at往左(不含)有序, 往右(含)也有序
    if(target == nums[0]){ return 0; }
    if(target == nums[numsSize - 1]){ return numsSize - 1; }
    if(target == nums[rotated_at]){ return rotated_at; }
    int t = bin_search(nums, 0, rotated_at - 1, target);
    if( t >= 0 ){ return t; }
    t = bin_search(nums, rotated_at, numsSize - 1, target);
    if( t >= 0 ){ return t; }
    return -1;
}

int main(){
    int nums[1] = {1};
    int ret = search(nums, 1, 0);
    return 1;
}