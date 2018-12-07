// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 5000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode *ElemType;

typedef struct {
    ElemType elems[MAX_SIZE];
    int size;
    int rear;
    int front;
} Queue;

Queue * CreateQueue(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    if(!q){ exit(1); }
    q->rear = q->front = 0;
    q->size = MAX_SIZE;
    return q;
}

void DestroyQueue(Queue * q){
    free(q);
}

bool IsFullQueue(Queue * q){
    if ((q->rear + 1) % q->size == q->front){ return true; }
    return false;
}

bool IsEmpltyQueue(Queue *q){
    if(q->rear == q->front){ return true; }
    return false;
}

void PushToQueue(Queue *q, ElemType e){
    if (IsFullQueue(q)){ return; }
    q->elems[q->rear] = e;
    q->rear = (q->rear + 1) % q->size;
}

ElemType PopFromQueue(Queue *q){
    if (IsEmpltyQueue(q)){ return NULL; }
    ElemType ret = q->elems[q->front];
    q->front = (q->front + 1) % q->size;
    return ret;
}

int maxDepth(struct TreeNode* root) {
    if(!root){return 0;}
    int ld = maxDepth(root->left), rd = maxDepth(root->right);
    if(ld>rd){ return ld+1;} else { return rd + 1;}

}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if(!root){
        *columnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    // 从底向上的层次遍历, 只需要在层次遍历的基础上, 反序最后的结果
    Queue * q = CreateQueue();
    PushToQueue(q, root);
    int depth = maxDepth(root);
    int ** origin_ret = (int **)malloc(sizeof(int *)*depth);
    int* origin_sizes = (int *)malloc(sizeof(int)*depth); // 有多少层, 就有多少行
    int ** ret = (int **)malloc(sizeof(int *)*depth);
    int* sizes = (int *)malloc(sizeof(int)*depth); // 有多少层, 就有多少行

    int level = 0;
    while(!IsEmpltyQueue(q)){ // 队空即停
    // 依赖一个隐藏特性: 在开始POP的时候队列里有多少东西, 都是同一层的东西
        int length = q->rear - q->front; // 当前层内有多少元素, 暂不考虑循环的问题
        int * tmp = (int *)malloc(sizeof(int)*length);
        for(int i=0; i<length; i++){
            struct TreeNode * cur = PopFromQueue(q);
            tmp[i] = cur->val;
            if(cur->left){PushToQueue(q, cur->left);}
            if(cur->right){PushToQueue(q, cur->right);}
        }
        origin_ret[level] = tmp;
        origin_sizes[level] = length; // 当前层的长度;
        level++;
    }
    for(int j = 0; j < depth; j++){
        ret[j] = origin_ret[depth-1-j];
        sizes[j] = origin_sizes[depth-1-j];
    }
    *returnSize = level;
    *columnSizes = sizes;
    return ret;
}