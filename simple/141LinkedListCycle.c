// https://leetcode-cn.com/problems/linked-list-cycle/description/

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


bool hasCycle(struct ListNode *head) {
    if(!head){return false;}
    struct ListNode * slow=head, *fast=head;
    while(1){
        if(!slow->next){return false;}
        if(!fast->next){return false;}
        if(!fast->next->next){return false;}
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}