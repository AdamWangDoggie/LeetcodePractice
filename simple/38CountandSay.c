// https://leetcode-cn.com/problems/count-and-say/description/
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 5000

char* next(char* pre){
    char *ret = (char*)malloc(sizeof(char)*MAX_SIZE);
    int i = 0, j = 0;
    while(1){
        if(pre[i]=='\0'){
            ret[j]='\0';    
            free(pre);
            return ret;
        }
        int multi = 1;
        while(pre[i+multi]==pre[i]){
            multi++;
        }
        ret[j++] = '0' + multi;
        ret[j++] = pre[i];
        i+=multi;
    }
}

char* countAndSay(int n) {
    char* ret = (char*)malloc(sizeof(char)*MAX_SIZE);
    ret[0] = '1'; ret[1] = '\0';
    for(int i = 1; i < n; i++){
        ret = next(ret);
    }
    return ret;
}

int main(){
    char* me = countAndSay(30);
    free(me);
    return 1;
}


/*
1. 1
2. 11
3. 21
4. 1211
5. 111221
6. 312211
7. 13112211
*/