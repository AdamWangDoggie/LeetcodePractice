// https://leetcode-cn.com/problems/sqrtx/description/
#include <stdio.h>


// 即找到最大的平方小于x的数
// 使用long类型来解决越界
int mySqrt(int x) {
    long input = (long)x;
    long min = 0, max = input;
    while(1){
        long tmp = min + (max - min) / 2;
        if( tmp * tmp == input){ return tmp; }
        if( tmp * tmp > input ){ max = tmp; continue; }  // 更新区间
        if( tmp * tmp < input ){
            if( (tmp + 1) * (tmp + 1) > input){ return tmp;}
            else if ( (tmp + 1)*(tmp + 1)==input ){ return tmp + 1;}
            else{ min = tmp; continue; }
        }
    }
}

int main(){
    int i = 2147395599;
    int a = mySqrt(i);
    printf("final: %d\n", a);
}