Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

struct ListNode* reverseKGroup(struct ListNode* head,int k){
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *prev=&dummy,*curr,*next,*tail;
    int i,count;
    while(1){
        count=0;
        tail=prev;
        while(tail->next&&count<k)
        {
            tail=tail->next;count++;
        }
        if(count<k)
          break;
        curr=prev->next;
        next=curr->next;
        for(i=1;i<k;i++)
        {
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=curr->next;
        }
        prev=curr;
    }
    return dummy.next;
}
