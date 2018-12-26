// https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/
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

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(!head){ return head; }
    struct ListNode* ret=head;
    while(ret){
        if(ret->val==val){
            ret = ret->next;
        }else{
            break;
        }
    }

    struct ListNode* h = ret;
    
    while(h&&h->next){
        if(h->next->val == val){
            h->next = h->next->next;
            continue;
        }
        h = h->next;
    }
    return ret;
}