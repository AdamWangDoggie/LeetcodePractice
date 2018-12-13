// https://leetcode-cn.com/problems/excel-sheet-column-title/description/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 500
typedef int ElemType;

typedef struct {
    ElemType *elems;
    int top;
    int size;
} Stack;

Stack * CreateStack(){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->elems = (ElemType *)malloc(sizeof(ElemType)*MAX_SIZE);
    stack->size = MAX_SIZE;
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
    s->elems[s->top + 1] = e;
    s->top++;
}

ElemType PopFromStack(Stack *s){
    ElemType ret = s->elems[s->top];
    s->top--;
    return ret;
}

// 思路比较拗人, 如果用171反推可能会好一点
char* convertToTitle(int n) {
    Stack * s = CreateStack();
    while(n>0){
        int t = (n-1) % 26; // 这里是因为要用A去加
        PushIntoStack(s, t);
        n = (n-1) / 26; // 这里要确保尾项被干掉, 因为作为26进制, 没有0而且Z竟然可以代表26沃日
    }
    char * ret = (char *)malloc(sizeof(char)* (s->top + 2));
    int tail = s->top + 1;
    ret[tail] = '\0';
    for(int i = 0; i < tail; i++){
        int c = PopFromStack(s);
        if(c < 0){
            ret[i] = 'Z';
        }
        else {
            ret[i] = c + 'A';
        }
    }
    return ret;
}

int main(){
    int i = 18278;
    char* ret = convertToTitle(i);
    return 1;
}