// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head){return NULL; }
    struct ListNode* ret = head, *tail = head;
    while(head->next){
        if(head->next->val==tail->val){
            head = head->next;
        } else {
            tail->next = head->next;
            tail = tail->next;
            head = head->next;
        }
    }
    tail->next = NULL;
    return ret;
}