// https://leetcode-cn.com/problems/symmetric-tree/description/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 5000

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

typedef struct TreeNode *ElemType;

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

struct TreeNode *nextFromLeft(Stack *s){
    struct TreeNode *cur = PopFromStack(s);
    if(cur){
        PushIntoStack(s, cur->right);
        PushIntoStack(s, cur->left); // 后进先出
    }
    return cur;
}

struct TreeNode *nextFromRight(Stack *s){
    struct TreeNode *cur = PopFromStack(s);
    if(cur){
        PushIntoStack(s, cur->left); // 后进先出
        PushIntoStack(s, cur->right);
    }
    return cur;
}

// 迭代
bool isSymmetric(struct TreeNode* root) {
    if(!root){return true;}
    // 用两个栈, 按遍历数列 左子树从左到右, 右子树从右到左
    Stack *stackLeft = CreateStack();
    Stack *stackRight = CreateStack();
    PushIntoStack(stackLeft, root->left);
    PushIntoStack(stackRight, root->right);
    while(!IsEmptyStack(stackLeft) && !IsEmptyStack(stackRight)){
        struct TreeNode *left = nextFromLeft(stackLeft);
        struct TreeNode *right = nextFromRight(stackRight);
        if(!left && !right){continue;}
        if(!left && right){return false;}
        if(left && !right){return false;}
        if(left->val != right->val){return false;}
    }
    if(!IsEmptyStack(stackLeft) && IsEmptyStack(stackRight)){ return false;}
    if(IsEmptyStack(stackLeft) && !IsEmptyStack(stackRight)){ return false;}
    return true;
}

// 递归
bool reverseEqual(struct TreeNode* t1, struct TreeNode* t2){
    // 翻转相等: t1和t2节点值相等, 且t1左与t2右翻转相等, t1右与t2左翻转相等
    if(!t1 && !t2){return true;}
    if(!t1 && t2){return false;}
    if(t1 && !t2){return false;}
    if(t1->val != t2->val){return false;}
    return reverseEqual(t1->left, t2->right) && reverseEqual(t1->right, t2->left);
}

bool isSymmetricRecursive(struct TreeNode* root) {
    if(!root){return true;}
    return reverseEqual(root->left, root->right);
}

int main(){
    struct TreeNode *ll = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ll->val = 3; ll->left = NULL; ll->right = NULL;
    struct TreeNode *lr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    lr->val = 4; lr->left = NULL; lr->right = NULL;

    struct TreeNode *rl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    rl->val = 4; rl->left = NULL; rl->right = NULL;
    struct TreeNode *rr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    rr->val = 3; rr->left = NULL; rr->right = NULL;

    struct TreeNode *left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    left->val = 2; left->left = ll; left->right = lr;
    struct TreeNode *right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    right->val = 2; right->left = rl; right->right = rr;


    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 1; root->left = left; root->right = right;


    bool res = isSymmetric(root);
    printf("res: %d\n", res);
    return 1;
}