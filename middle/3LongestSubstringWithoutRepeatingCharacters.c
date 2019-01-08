//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <stdbool.h>
#include <memory.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int exists[256];
    memset(exists, -1, 256*sizeof(int));
    
    int index=0, start=0, ret=0;
    while (s[index] != '\0'){
        char ord_c = s[index];
        if(exists[ord_c] < 0 || exists[ord_c] < start){
            exists[ord_c] = index;  // 记下这个字符的索引
            if(index-start + 1> ret){
                ret = index-start + 1;
                printf("");
            }
            index++;
        }
        else {
            start = exists[ord_c] + 1;
            exists[ord_c] = -1;
        }
        
    }
    return ret;
}

int main(){
    int len = lengthOfLongestSubstring("abba");

    return 1;
}