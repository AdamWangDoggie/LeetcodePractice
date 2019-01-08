//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include <stdbool.h>
#include <memory.h>
#include <stdio.h>



// 只需要维护start的位置就好了, start->index是子串的范围, 
// int lengthOfLongestSubstring(char* s) {
//     int exists[256];
//     memset(exists, -1, 256*sizeof(int));
//     int index=0, start=0, ret=0;
//     while (s[index] != '\0'){
//         char ord_c = s[index];
//         if(exists[ord_c] < start){
//             exists[ord_c] = index;  // 记下这个字符的索引
//             if(index-start + 1> ret){
//                 ret = index-start + 1;
//             }
//             index++;
//         }
//         else {
//             start = exists[ord_c] + 1;
//         }
        
//     }
//     return ret;
// }

int max(int a, int b){
    if(a > b){return a;}else{return b;}
}

int lengthOfLongestSubstring(char* s) {
    int exists[256];
    memset(exists, -1, 256*sizeof(int));

    int index=0, left=-1, ret=0;
    while (s[index] != '\0'){
        char ord_c = s[index];
        left = max(left, exists[ord_c]);
        exists[ord_c] = index;
        ret = max(index-left, ret);
        index++;
    }
    return ret;
}


int main(){
    int len = lengthOfLongestSubstring("abcabcabb");

    return 1;
}