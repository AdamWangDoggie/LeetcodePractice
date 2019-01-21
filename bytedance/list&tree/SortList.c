// 排序链表
// 要求时间O(nlogn), 故快排不满足(最坏O(n^2)), 要用归并(平均,最坏都是O(nlogn))
/* 需注意的地方:
    1. 链表找中点用快慢指针遍历
    2. 左右两半去merge的时候, 需要将两边拆开

*/
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

struct ListNode * get_node( int val){
    struct ListNode* ret = (struct ListNode *)malloc(sizeof(struct ListNode));
    ret->val = val; ret->next = NULL;
    return ret;
}

struct ListNode* middle(struct ListNode * head){
    struct ListNode* slow = head, *fast = head->next;
    while( fast && fast->next ){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* merge(struct ListNode * l1, struct ListNode * l2){
    if(!l1){return l2;}
    if(!l2){return l1;}
    struct ListNode *ret, *tmp;
    
    if(l1->val <= l2->val){ ret = l1; l1 = l1->next;} 
    else { ret = l2; l2 = l2->next; }
    
    tmp = ret;
    while(l1 && l2){
        if(l1->val <= l2->val){ tmp->next = l1; tmp = tmp->next; l1 = l1->next; } 
        else { tmp->next = l2; tmp = tmp->next; l2 = l2->next; }
    }
    if(l1){ tmp->next = l1; }
    if(l2){ tmp->next = l2; }
    return ret;
}

struct ListNode* merge_sort(struct ListNode* head){
    if(!head || !head->next){ return head; }
    struct ListNode* mid = middle(head), *tmp;

    tmp = mid->next;
    mid->next = NULL;
    mid = tmp;
    
    struct ListNode* left = merge_sort(head), *right = merge_sort(mid);
    return merge(left, right);
}


struct ListNode* sortList(struct ListNode* head) {
    return merge_sort(head);
}

int main(){
    struct ListNode* in = get_node(4);
    in->next = get_node(2);
    in->next->next = get_node(1);
    in->next->next->next = get_node(3);

    struct ListNode * ret = sortList(in);

    return 1;
}