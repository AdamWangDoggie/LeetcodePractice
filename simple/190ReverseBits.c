// https://leetcode-cn.com/problems/reverse-bits/description/
#include <stdlib.h>

// deal with real bits, O(32)
uint32_t reverseBits(uint32_t n) {
    uint32_t retval = 0;
    for (int i = 32; i > 0; --i) {
        retval <<= 1;
        retval += (n & 1);
        n >>= 1;
    }    
    return retval;
}

// deal it as int, O(32)
uint32_t reverseBits2(uint32_t n) {
    uint32_t ret = 0, t = 0;
    while(n){
        ret = ret*2 + n % 2;
        n/=2;
        t++;
    }
    while(t < 32){
        ret*=2; t++;
    }
    return ret;
}