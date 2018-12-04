// https://leetcode-cn.com/problems/roman-to-integer/description/
#include <stdio.h>
#include <stdbool.h>

/*
    M             1000
    D             500
    C             100
    L             50
    X             10
    V             5
    I             1
*/

int romanToInt(char* s) {
    int ret = 0, index = 0;
    while(1){
        if(s[index] == '\0'){
            break;
        } else if(s[index]=='M'){
            ret += 1000;
        } else if(s[index]=='D'){
            ret += 500;
        } else if(s[index]=='C'){
            if(s[index+1]=='D'){
                ret += 400;
                index++;
            } else if(s[index+1]=='M'){
                ret += 900;
                index++;
            } else{
                ret += 100;
            }
        } else if (s[index]=='L'){
            ret += 50;
        } else if (s[index]=='X'){
            if(s[index+1]=='L'){
                ret += 40; index++;
            } else if (s[index+1]=='C'){
                ret += 90; index++;
            } else{
                ret += 10;
            }
        } else if(s[index]=='V'){
            ret += 5;
        } else if(s[index]=='I'){
            if(s[index+1]=='V'){
                ret += 4; index++;
            } else if(s[index+1]=='X'){
                ret += 9; index++;
            } else {
                ret += 1;
            }
        }
        index++;
    }
    return ret;
}
