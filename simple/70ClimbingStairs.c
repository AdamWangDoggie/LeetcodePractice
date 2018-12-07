// https://leetcode-cn.com/problems/climbing-stairs/description/
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

// 动态规划: 带存储的递归
int cal(int * mem, int n){
    int ret=0;
    if(mem[n]){ 
        return mem[n];
    }
    if(n==1){ret = 1;}
    else if(n==2){ret = 2;}
    else{
        ret = cal(mem, n-1) + cal(mem, n-2);
    }

    mem[n] = ret;
    return ret;
}

int climbStairs(int n) {
    if(n<=0){ return 0; }
    int * mem = (int*)malloc((n+1)*sizeof(int));
    memset(mem, 0, sizeof(int)*(n+1));
    int ret = cal(mem, n);
    free(mem);
    return ret;
}

int main(){
    int n = 13;
    int ret = climbStairs(n);
    printf("%d ways to climb %d stairs\n", ret, n);
    
    return 1;
}