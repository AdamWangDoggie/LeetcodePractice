// https://leetcode-cn.com/problems/valid-parentheses/description/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct {
    char *c;
    int top;
    int size;
} Stack;

Stack * CreateStack(){
    int size = MAX_SIZE;
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->c = (char *)malloc(sizeof(char)*size);
    stack->size = size;
    return stack;
}

void ClearStack(Stack * s){
    s->top = -1;
}

void DestroyStack(Stack *s){
    free(s->c);
    free(s);
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

void PushIntoStack(Stack *s, char e){
    if (IsFullStack(s)) {
        return;
    }
    s->c[s->top + 1] = e;
    s->top++;
}

char PopFromStack(Stack *s){
    if (IsEmptyStack(s)){
        return '\0';
    }
    char ret = s->c[s->top];
    s->top--;
    return ret;
}

bool pair(char a, char b){
    if(a == '(' && b == ')'){ return true; }
    if(a == '[' && b == ']'){ return true; }
    if(a == '{' && b == '}'){ return true; }
    return false;
}

bool isValid(char* s) {
    bool flag = true;
    if(s==""){ return true; }
    Stack *stk = CreateStack();
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            PushIntoStack(stk, s[i]);
            continue;
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            char t = PopFromStack(stk);
            if(!pair(t, s[i])){
                flag = false;
                break;
            }
        }
    }
    if(!IsEmptyStack(stk)){
        flag = false;
    }
    DestroyStack(stk);
    return flag;
}

int main(){
    char *s = "{[}[{}{{({)){[}([]{)}({())[}[}";
    printf("%d \n", isValid(s));
    return 1;
}