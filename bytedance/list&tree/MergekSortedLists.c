/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* merge( struct ListNode* a, struct ListNode * b){
    if(!a){return b;} if(!b){return a;}
    struct ListNode* ret, *tmp;
    if(a->val <= b->val){ ret = a; a = a->next; } 
    else { ret = b; b = b->next; }
    tmp = ret;
    while(a&&b){
        if(a->val <= b->val){
            tmp->next = a;
            tmp = tmp->next;
            a = a->next;
        }
        else {
            tmp->next = b;
            tmp = tmp->next;
            b = b->next;
        }
    }
    if(!a){ tmp->next = b;}
    if(!b){ tmp->next = a;}
    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0){ return NULL; }
    if(listsSize == 1){ return lists[0]; }
    if(listsSize == 2){ return merge(lists[0], lists[1]); }

    int mid = listsSize / 2;
    return merge( mergeKLists(lists, mid), mergeKLists(lists + mid, listsSize - mid));
}
