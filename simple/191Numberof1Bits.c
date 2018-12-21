// https://leetcode-cn.com/problems/number-of-1-bits/description/
#include <stdlib.h>

int hammingWeight(uint32_t n) {
    int ret = 0;
    for(int i=0; i<32; i++){
        ret += n&1;
        n>>=1;
    }
    return ret;
}