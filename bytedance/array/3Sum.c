// 三数之和, 与两数之和类似
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct array {
    int ** c;
    int length;
    int size;
} array;

array * get_array(){
    array* ret = (array*)malloc(sizeof(array));
    ret->length = 0; ret->size = 10;
    ret->c = (int **)malloc(sizeof(int*)*ret->size);
    return ret;
}

void append(array* a, int * e){
    // 已存在就算了, 这里假设了所有的e都是有序的
    if(a->length >= a->size){
        int new_size = a->size + 10;
        a->c = (int**)realloc(a->c, sizeof(int*)*new_size);
        a->size = new_size;
    }
    a->c[a->length++] = e;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    // 先排序
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    array * ret = get_array();

    for(int i = 0; i < numsSize - 2; i++){
        if(i>0 && nums[i] == nums[i-1]){ continue; } // 拿到下一个不一样的i
        int j = i+1, k = numsSize - 1;
        while(j < k){
            int cur_sum = nums[i] + nums[j] + nums[k];
            if(cur_sum == 0){
                int * e = (int *)malloc(sizeof(int)*3);
                e[0] = nums[i]; e[1] = nums[j]; e[2] = nums[k];
                append(ret, e);
                j++; k--;
                while(j < k && nums[j] == nums[j-1]){
                    j++; // 拿到下一个不一样的j
                }
                while(j < k && nums[k] == nums[k + 1]){
                    k--;  // 拿到下一个不一样的k
                }
            } else if(cur_sum > 0){
                k--;
            } else if(cur_sum < 0){
                j++;
            }
        }
    }

    *returnSize = ret->length;
    return ret->c;
}

// int main(){
//     int in[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//     int cnt;
//     int ** ret = threeSum(in, 15, &cnt);

//     return 1;
// }


int** threeSumNew(int* nums, int numsSize, int* returnSize) {
    int count = 0;
    int **buffer;
    int *postive;
    int third=0;
            
    buffer = (int **)calloc( numsSize*numsSize-1*numsSize-2,sizeof(int *));
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    // 最后一个数必为正数, positive中存的是非负数
    postive = calloc(nums[numsSize-1]+1, sizeof(int));
        
    for(int i = numsSize-1; nums[i]>=0 && i>=0 ;i--)
        postive[nums[i]]++;
    
    for(int i=0; nums[i]<=0; i++){
        if(i>=1 && nums[i]==nums[i-1])
            continue;    
                
        for(int j=i+1; j< numsSize-1; j++){
            if(j>i+1 && nums[j]==nums[j-1])
                continue;
            
            if(nums[i]+nums[j]>0)
                break;
            
            third = -1*(nums[i]+nums[j]);
            if(nums[numsSize-1]>= third){
                // 首先: 存在该非负数
                if(
                    // 有该数且该数最大
                    (postive[third] >=1 && third > nums[j] ) ||
                    // 后两数相等且该数不止1个
                    (third == nums[j] && third !=nums[i] && postive[third] >1) ||
                    // 三个数都相等且该数不止2个
                    (third == nums[j] && third ==nums[i] && postive[third] >2)
                ){
                    buffer[count] = calloc(3, sizeof(int));
                    buffer[count][0]=nums[i];
                    buffer[count][1]=nums[j];
                    buffer[count][2]= -1*(nums[i]+nums[j]);
                    count++;
                }
            }
         }
    }
    
    *returnSize=count;
    
    return buffer;
    
}

int main(){
    int in[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int cnt;
    int ** ret = threeSumNew(in, 15, &cnt);

    return 1;
}