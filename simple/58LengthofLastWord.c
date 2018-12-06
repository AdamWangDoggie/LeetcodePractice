// https://leetcode-cn.com/problems/length-of-last-word/description/
#include <stdbool.h>

int lengthOfLastWord(char* s) {
    int ret = 0;
    bool space_flag = false;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i]!=' '){
            if(space_flag){
                space_flag = false;
                ret = 0;
            }
            ret++;
        } else {space_flag = true;}
    }
    return ret;
}