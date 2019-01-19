// 朋友圈
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

typedef struct Queue {
    int * items;
    int length;
} Queue;

Queue * get_queue(int size){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(sizeof(int)*size);
    q->length = 0;
    return q;
}

void push(Queue* q, int e){
    q->items[q->length++] = e;
}

int pop(Queue* q){
    if(q->length <= 0){
        return -1;
    }
    return q->items[--q->length];
}


void explore(int ** M, int size, int* people, int i){
    people[i] = 1;
    Queue * q = get_queue(size);
    for(int j = 0; j<size; j++){
        if(M[i][j]==1){
            people[j] = 1;
            push(q, j);
        }
    }
    int n = pop(q);
    while( n >=0 ){
        // people[n] = 1;
        for(int k = 0; k < size; k++){
            if(M[n][k] == 1 && people[k] == 0){
                people[k] = 1;
                push(q, k);
            }
        }
        n = pop(q);
    }
}

int findCircleNum(int** M, int MRowSize, int MColSize) {
    int ret = 0;
    int people[MRowSize];
    memset(people, 0, sizeof(int)*MRowSize);

    for(int i = 0; i < MRowSize; i++){
        if(people[i]==0){
            explore(M, MRowSize, people, i);
            ret++;
        }
    }

    return ret;
}
