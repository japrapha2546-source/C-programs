You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

struct ListNode* removeNodes(struct ListNode* head){
    struct ListNode *prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    curr=head;
    prev=head;
    int maxVal=head->val;
    curr=curr->next;
    while(curr){
        if(curr->val<maxVal)
           prev->next=curr->next;
        else
        {
            maxVal=curr->val;
            prev=curr;
            }
        curr=prev->next;
    }
    prev=NULL;
    curr=head;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
