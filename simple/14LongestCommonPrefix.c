// https://leetcode-cn.com/problems/longest-common-prefix/description/
#include <stdio.h>
#include <stdlib.h>

int commonIndex(char ** strs, int strsSize, char* sentinel){
    for(int i=0;;i++){
        if(sentinel[i]=='\0'){
            return i;
        }
        for(int j=0; j<strsSize;j++){
            if(sentinel[i] != strs[j][i]){
                return i;
            }
        }
    }
}


char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0){return "";}
    if (strsSize == 1){return strs[0];}
    char * sentinel = strs[0];
    int i = commonIndex(strs, strsSize, sentinel);
    if(i==0){return "";}
    char *ret = (char *)malloc(sizeof(char)*(i+1));
    for(int tmp=0;tmp<i;tmp++){
        ret[tmp] = sentinel[tmp];
    }
    ret[i] = '\0'; // this char is so fucking important
    return ret;
}

int main(){
    char *input[] = {"c","c"};
    char * prefix = longestCommonPrefix(input, 2);
    printf("%s \n", prefix);
    free(prefix);
}