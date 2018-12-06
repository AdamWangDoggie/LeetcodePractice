// https://leetcode-cn.com/problems/plus-one/description/
#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int)*(digitsSize+1));
    ret[0] = 0;
    int i=digitsSize-1, j=digitsSize;
    
    int flag = 1;
    while(i>=0&&j>=0){
        if(flag){
            ret[j] = digits[i] + 1;
            if(ret[j] > 9){ret[j] = ret[j] % 10;} 
            else {flag = 0;}
        } 
        else{ret[j] = digits[i];}
        i--;j--;
    }
    // 没处理完的进位
    if(flag){
        ret[0] = 1;
    }
    printf("ret[0]: %d, ret[1]: %d\n", ret[0], ret[1]);
    if(ret[0]>0){
        *returnSize = digitsSize+1;
    }else{
        for(int t = 0; t<digitsSize; t++){
            ret[t] = ret[t+1];
        }
        *returnSize = digitsSize;
    }
    return ret;
}

int main(){
    int a[1] = {9};
    int b;
    plusOne(a, 1, &b);
    return 1;
}