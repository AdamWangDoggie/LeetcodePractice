#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>

typedef struct stringer {
    char* s;
    int sentinal;
} stringer;

stringer* get_stringer(char* s){
    stringer * ret = (stringer*)malloc(sizeof(stringer));
    ret->s = s;
    ret->sentinal = 0;
    return ret;
}

char * next(stringer* st){
    if(st->s[st->sentinal]=='\0'){return NULL;}

    int i = st->sentinal;
    while(st->s[i] == '/'){
        i++;
    }
    int j = i; //首个有用的字符索引;
    while(st->s[j] != '/' && st->s[j] != '\0'){
        j++;
    }
    char* ret = (char*)malloc(sizeof(char)*(j-i+1));
    for(int t = i; t < j; t++){
        ret[t-i] = st->s[t];
    }
    ret[j-i] = '\0';
    st->sentinal = j;
    return ret;
}

void append(stringer* st, char * s){
    st->s[st->sentinal++] = '/';
    for(int i=0;s[i]!= '\0';i++){
        st->s[st->sentinal++] = s[i];
    }
    st->s[st->sentinal] = '\0';
}

void back(stringer* st){
    if(st->sentinal==0){ 
        return; 
    }
    while(st->s[st->sentinal]!= '/'){
        st->s[st->sentinal--] = '\0';
    }
    st->s[st->sentinal] = '\0';
}


char* simplifyPath(char* path) {
    stringer * org = get_stringer(path);
    char* r = (char*)malloc(sizeof(char)*(strlen(path)+1));
    memset(r, '\0', sizeof(char)*(strlen(path)+1));
    stringer* ret = get_stringer(r);
    char* ne = next(org);
    while(ne && strlen(ne)>0){
        if(strcmp(ne, ".")==0){} 
        else if (strcmp(ne, "..")==0){
            back(ret);
        } else {
            append(ret, ne);
        }
        ne = next(org);
    }
    if(strlen(ret->s)==0){
        ret->s[0] = '/';
    }
    return ret->s;
}

int main(){
    char* ret = simplifyPath("///oDPc///PnF/esaB/vPH/./qZl///./qC/../../////xFNu/cBh///qZ///XlmOR/SkC/./qKbXI/././P/dcFKB/n//");
    return 1;
}