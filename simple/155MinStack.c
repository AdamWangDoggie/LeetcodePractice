// https://leetcode-cn.com/problems/min-stack/description/

#include <stdlib.h>
#include <limits.h>

typedef struct MinStack {
    int *elems;
    int size;
    int top;
    struct MinStack * mins;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack * min = (MinStack *)malloc(sizeof(MinStack));
    min->elems = (int *)malloc(sizeof(int)*maxSize);
    min->size = maxSize;
    min->top = -1;
    min->mins = NULL;

    MinStack * s = (MinStack *)malloc(sizeof(MinStack));
    s->elems = (int *)malloc(sizeof(int)*maxSize);
    s->size = maxSize;
    s->top = -1;
    s->mins = min;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    int to_push, cur_min;
    if(obj->top < 0){
        cur_min = x;
    } else {
        cur_min = minStackTop(obj->mins);
        if(x < cur_min){ cur_min = x; }
    }
    obj->top++; obj->mins->top++;
    obj->mins->elems[obj->mins->top] = cur_min;
    obj->elems[obj->top] = x;
}

void minStackPop(MinStack* obj) {
    obj->top--;
    obj->mins->top--;
}

int minStackTop(MinStack* obj) {
    return obj->elems[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return minStackTop(obj->mins);
}

void minStackFree(MinStack* obj) {
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */