// 相交链表
// 核心思路在于链表a+链表b的长度是一定相等的

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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