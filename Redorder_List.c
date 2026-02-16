Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

void reorderList(struct ListNode* head){
    if(!head || !head->next) 
        return;

    struct ListNode *slow=head, *fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    struct ListNode* second=slow->next;
    slow->next=NULL;

    struct ListNode* prev=NULL;
    struct ListNode* curr=second;
    while(curr){
        struct ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    second=prev;

    struct ListNode* first=head;
    while(second){
        struct ListNode* tmp1=first->next;
        struct ListNode* tmp2=second->next;
        first->next=second;
        second->next=tmp1;
        first=tmp1;
        second=tmp2;
    }
}
