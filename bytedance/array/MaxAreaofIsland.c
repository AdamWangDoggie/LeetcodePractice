// 岛屿的最大面积
#include <stdlib.h>

typedef struct node {
    int row;
    int col;
    struct node* next;
} node;

node* get_node(int row, int col){
    node* ret = (node* )malloc(sizeof(node));
    ret->row = row; ret->col = col;
    ret->next = NULL;
    return ret;
}

typedef struct Queue {
    node* head;
    node* tail;
} Queue;

Queue * get_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void push(Queue* q, node* n){
    if(q->tail == NULL){
        q->tail = n;
        if(q->head == NULL){
            q->head = q->tail;
        }
    } else {
        q->tail->next = n;
        q->tail = q->tail->next;
    }
}

node* pop(Queue* q){
    node * ret = q->head;
    if(q->head != NULL){
        q->head = q->head->next;
        if(q->head == NULL){
            q->tail = NULL;
        }
    }
    return ret;
}

// BFS
int explore(int ** grid, int gridRowSize, int gridColSize, int row, int col){
    if(grid[row][col]==0){ return 0; }
    Queue * q = get_queue();
    node* n = get_node(row, col);
    int ret = 0; 

    grid[n->row][n->col] = 0;
    while(n){
        ret ++;
        // 上
        if( n->row + 1 < gridRowSize && grid[n->row + 1][n->col] == 1){
            push(q, get_node(n->row + 1, n->col));
            grid[n->row + 1][n->col] = 0;
        }
        // 下
        if( n->row - 1 >= 0 && grid[n->row - 1][n->col] == 1){
            push(q, get_node(n->row - 1, n->col));
            grid[n->row - 1][n->col] = 0;
        }
        // 左
        if( n->col - 1 >= 0 && grid[n->row][n->col - 1] == 1){
            push(q, get_node(n->row, n->col -1 ));
            grid[n->row][n->col - 1] = 0;
        }
        // 右
        if (n->col + 1 < gridColSize && grid[n->row][n->col + 1] == 1){
            push(q, get_node(n->row, n->col + 1));
            grid[n->row][n->col + 1] = 0;
        }
        n = pop(q);
    }
    return ret;
}

int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize) {
    int ret = 0;
    for(int row = 0; row < gridRowSize; row++){
        for( int col = 0; col < gridColSize; col++){
            int cur = explore(grid, gridRowSize, gridColSize, row, col);
            if(cur > ret){ ret = cur;}
        }
    }
    return ret;
}

int main(){
    int ** grid = (int **)malloc(sizeof(int*)*4);
    grid[0] = (int*)malloc(sizeof(int)*5);
    grid[0][0] = 1; grid[0][1] = 1; grid[0][2] = 0; grid[0][3] = 0; grid[0][4] = 0;
    grid[1] = (int*)malloc(sizeof(int)*5);
    grid[1][0] = 1; grid[1][1] = 1; grid[1][2] = 0; grid[1][3] = 0; grid[1][4] = 0;
    grid[2] = (int*)malloc(sizeof(int)*5);
    grid[2][0] = 1; grid[2][1] = 1; grid[2][2] = 0; grid[2][3] = 0; grid[2][4] = 0;
    grid[3] = (int*)malloc(sizeof(int)*5);
    grid[3][0] = 1; grid[3][1] = 1; grid[3][2] = 0; grid[3][3] = 0; grid[3][4] = 0;
    int ret = maxAreaOfIsland(grid, 4, 5);
    return ret;
}