// https://leetcode-cn.com/problems/palindrome-number/description/

#include <stdio.h>
#include <stdbool.h>


// todo: why don't u just make the input to a array to avoid loop in loop?

bool isPalindrome(int x) {
    if (x<0){return false;}
    if (x<10){return true;}
    int bits=0, inp = x;
    // inp: x是多少位的十进制数
    while(inp){
        bits++;
        inp /=10;
    }
    // 到中间即停止
    int head, tail;
    for(int i = 0; i<bits/2;i++){
        int mulh = 1, mult = 1;
        for(int j=0; j<i; j++) {mult*=10;}
        for(int k=0; k<bits-1-i; k++) {mulh*=10;}
        head = x / mulh % 10;
        tail = x / mult % 10;
        if (head!=tail){
            return false;
        }
    }
    return true;
}

int main(){
    int i = 1002001;
    int j = 1000021;
    printf("%d: %d, %d: %d\n", i, isPalindrome(i), j, isPalindrome(j));
}