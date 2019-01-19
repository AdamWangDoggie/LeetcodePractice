struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1){return l2;}
    if(!l2){return l1;}
    struct ListNode *ret, *tmp;
    if(l1->val <= l2->val){
        ret = l1;
        l1 = l1->next;
    } else {
        ret = l2; 
        l2 = l2->next;
    }
    tmp = ret;
    while(l1 && l2){
        if(l1->val <= l2->val){
            tmp->next = l1;
            tmp = tmp->next;
            l1 = l1->next;
        } else {
            tmp->next = l2;
            tmp = tmp->next;
            l2 = l2->next;
        }
    }
    if(l1){
        tmp->next = l1;
    }
    if (l2){
        tmp->next = l2;
    }
    return ret;
}