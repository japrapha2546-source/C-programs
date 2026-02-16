struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
    if(!headA || !headB) 
        return NULL;

    struct ListNode *pA=headA, *pB=headB;

    while(pA != pB){
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }

    return pA;
}
