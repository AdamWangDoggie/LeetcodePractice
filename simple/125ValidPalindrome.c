// https://leetcode-cn.com/problems/valid-palindrome/description/
#include <stdbool.h>
#include <string.h>

bool valid(char c){
    // 判断是否数字或字母
    return (c >= '0' && c<= '9') || (c >= 'a' && c<= 'z') || (c >= 'A' && c<='Z');
}

char lower(char c){
    if(c>='A' && c<='Z'){
        return c+32;
    }
    return c;
}

bool isPalindrome(char* s) {
    if(strlen(s)==0){return true;}
    int max_index = strlen(s) - 1;
    int i = 0, j = max_index;
    while(j > i){
        if(!valid(s[i])){ i++; continue; }
        if(!valid(s[j])){ j--; continue; }
        if(lower(s[i]) != lower(s[j])){
            return false;
        }
        i++; j--;
    }
    return true;
}

int main(){
    char* i = "race a car";
    bool ret = isPalindrome(i);
    return 1;
}