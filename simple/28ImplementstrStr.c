// https://leetcode-cn.com/problems/implement-strstr/description/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    if(needle[0]=='\0'){return 0;}  // 目标串为空直接返回0
    for(int start = 0;haystack[start]!='\0'; start++){
        bool flag;
        for(int i=start, j=0;;i++, j++){
            flag = true;
            if(needle[j]=='\0'){break;}  // 目标已结束
            if(haystack[i] != needle[j]){ flag=false; break; }  // 发现不同字符即停止, 即便是haystack[i] = '\0', 也在这里被处理, 不用单独看边界条件
        }
        if(flag){return start;} // 循环结束才知道结果, 所以使用一个flag
    }
    return -1;
}