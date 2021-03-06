// 翻转字符串里的单词, C语言要求空间O(1)
// 思路: 先完整翻转字符串, 且确保翻转完成后开头没有空格(即翻转前先处理尾部的空格)
// 再逐个翻转单词, 在翻转的过程中将词间空格翻转到尾部去, 也许类似冒泡排序?
// 最后用结束符'\0'写掉尾部的空格即可

#include <stdbool.h>
#include <string.h>

bool isSpace(char c){
    return c == ' ';
}

void reverseWord(char *s, int start, int end){
    while(start < end){
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++; end--;
    }
}

void reverseWords(char *s) {
    int sz = strlen(s);
    int start = 0, end = sz - 1;
    // 先忽略尾空格
    while(isSpace(s[end]) && end >= 0){
        end--;
    }
    // 翻转, 反转后头无空格
    reverseWord(s, start, end);
    // 翻转单词, 词中空格全部挪到最后
    int letter_count = 0;
    int i = 0;
    for(; i < sz - 1; i++){
        if(!isSpace(s[i])){
            letter_count++;
        }
        else{
            if(!isSpace(s[i-1])){
                reverseWord(s, start, i-1);
                start += letter_count + 1;
                letter_count = 0;
            }
        }
    }
    // 如果最后一个字符不是空格, 那么上面的循环不能覆盖, 额外一次反转
    if(!isSpace(s[i])){
        reverseWord(s, start, i);
    }

    // 再去掉尾空格
    while(isSpace(s[end]) && end >= 0){
        end--;
    }
    s[end+1] = '\0';
}


int main(){
    char test[3] = " 1";
    reverseWords(test);
    return 1;
}