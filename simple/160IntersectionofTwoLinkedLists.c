// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
// 思路牛逼 https://blog.csdn.net/qq_34364995/article/details/80518198


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
// 两个链表均对 自己+对方 做一次遍历, 若有交点, 则必然同时第二次到达交点, 若无交点, 则会遍历完成
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB){ return false;}
    bool doneA = false, doneB = false;
    struct ListNode *a = headA; struct ListNode *b = headB;

    while(a != b){
        a = a->next;
        if(!a){
            if(!doneA){
                a = headB; doneA = true;
            }
            else{ return NULL; }
        }
        b = b->next;
        if(!b){
            if(!doneB){
                b = headA; doneB = true;
            }
            else{ return NULL; }
        }
    }
    return a;
}