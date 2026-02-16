Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

struct ListNode* rotateRight(struct ListNode* head,int k){
    if(!head||!head->next||k==0) 
        return head;
    struct ListNode* tail=head;
    int n=1;
    while(tail->next)
        tail=tail->next,n++;
    k=k%n;
    if(k==0) 
        return head;
    tail->next=head;
    struct ListNode* newTail=head;
    for(int i=0;i<n-k-1;i++)
        newTail=newTail->next;
    struct ListNode* newHead=newTail->next;
    newTail->next=NULL;
    return newHead;
}
