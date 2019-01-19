// 反转链表

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


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *ret=NULL, *tmp=NULL;
    while(head){
        tmp = head;
        head = head->next;
        tmp->next = ret;
        ret = tmp;
    }
    return ret;
}

int main(){
    return 1;
}