// https://leetcode-cn.com/problems/add-binary/description/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef char ElemType;

typedef struct {
    ElemType *elems;
    int top;
    int size;
} Stack;

Stack * CreateStack(int size){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->elems = (ElemType *)malloc(sizeof(ElemType)*size);
    stack->size = size;
    return stack;
}

void DestroyStack(Stack *s){
    free(s);
    free(s->elems);
}

bool IsEmptyStack(Stack * s){
    if(s->top == -1){
        return true;
    } return false;
}

bool IsFullStack(Stack * s){
    if(s->top == s->size - 1){
        return true;
    } return false;
}

void PushIntoStack(Stack *s, ElemType e){
    if (IsFullStack(s)) {
        return;
    }
    s->elems[s->top + 1] = e;
    s->top++;
}

ElemType PopFromStack(Stack *s){
    if (IsEmptyStack(s)){
        return NULL;
    }
    ElemType ret = s->elems[s->top];
    s->top--;
    return ret;
}

char* addBinary(char* a, char* b) {
    // start from tail
    int ia=0, ib=0;
    while(a[ia+1]!='\0'){
        ia++;
    }
    while(b[ib+1]!='\0'){
        ib++;
    }
    int size;
    if(ia >= ib){ size = ia + 3;}else{ size = ib + 3;} // ia, ib都是索引, 需要+1, 最后的结束符需要+1, 可能进位需要+1
    Stack *s = CreateStack(size);
    PushIntoStack(s, '\0');

    bool flag = false;
    while(ia >= 0 && ib >= 0){
        int tmp = a[ia] - '0' + b[ib] - '0';
        if(flag){ tmp++; flag = false; }
        if(tmp / 2 >= 1){ flag = true; }
        PushIntoStack(s, tmp % 2 + '0');
        ia--; ib--;
    }
    while(ia >= 0){
        int tmp = a[ia] - '0';
        if(flag){ tmp++; flag=false; }
        if(tmp / 2 >= 1){ flag=true; }
        PushIntoStack(s, tmp % 2 + '0');
        ia--;
    }
    while(ib >= 0){
        int tmp = b[ib] - '0';
        if(flag){ tmp++; flag=false; }
        if(tmp / 2 >= 1){ flag=true; }
        PushIntoStack(s, tmp % 2 + '0');
        ib--;
    }
    if(flag){ PushIntoStack(s, '1'); }
    char * ret = (char*)malloc(sizeof(char)*(s->top+1));

    int ir = 0;
    while(!IsEmptyStack(s)){
        ret[ir] = PopFromStack(s);
        ir++;
    }
    DestroyStack(s);
    return ret;

}


int main(){
    char a[] = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    char b[] = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    char * ret = addBinary(a, b);
    printf("final: %s\n", ret);
}