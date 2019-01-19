// 两数相加

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

struct ListNode * get_node(int e){
    struct ListNode * ret = (struct ListNode* )malloc(sizeof(struct ListNode));
    ret->val = e;
    ret->next = NULL;
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret=NULL, *tail=NULL, *next = NULL;
    if(!l1){return l2;}
    if(!l2){return l1;}
    int add = 0;
    while(l1 && l2){
        int cur = l1->val + l2->val + add;
        if(!ret){
            ret = get_node(cur%10);
            tail = ret;
            add = cur / 10;
        } else{
            next = get_node(cur % 10);
            add = cur/10;
            tail->next = next;
            tail = tail->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if(!l1){
        while(l2){
            int cur = l2->val + add;
            next = get_node(cur % 10);
            add = cur/10;
            tail->next = next;
            tail = tail->next;
            l2 = l2->next;
        }
    }
    if(!l2){ 
        while(l1){
            int cur = l1->val + add;
            next = get_node(cur % 10);
            add = cur/10;
            tail->next = next;
            tail = tail->next;
            l1 = l1->next;
        }
    }
    if(add){
        tail->next = get_node(add);
    }

    return ret;
}
