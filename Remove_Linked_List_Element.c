Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

struct ListNode* removeElements(struct ListNode* head,int val){
    while(head!=NULL && head->val==val){
        head=head->next;
    }
    struct ListNode* curr=head;

    while(curr!=NULL && curr->next!=NULL){
        if(curr->next->val==val){
            curr->next=curr->next->next;
        }else{
            curr=curr->next;
        }
    }
    return head;
}
