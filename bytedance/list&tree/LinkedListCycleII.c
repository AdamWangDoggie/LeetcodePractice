// 环形链表II
// 设从头节点到入环点距离为x, 环全长y, 快慢指针相遇时, 快指针比慢指针多绕环一圈
// 设慢指针已走过d, 则快指针走过2d, 
// 则有 d - x = 2d - x - y 得 d = y, 设此时已入环长度为m, 则有 x + m = y 得 x = y - m 为剩下的环的长度
// 所以在快慢指针第一次相遇后, 将慢指针留在原地, 快指针移回头指针, 同时再以每次一步的速度走, 则会再次相遇在入环点

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

struct ListNode *detectCycle(struct ListNode *head) {
    if(!head || !head->next || !head->next->next){ return NULL; }
    struct ListNode * slow = head->next, * fast = head->next->next;
    
    // 走到第一次相遇
    while(slow != fast){
        if(!slow || !slow->next || !fast || !fast->next){ return NULL; }
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
