Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

bool isPalindrome(struct ListNode* head){
    if(head==NULL||head->next==NULL) return true;
    struct ListNode *slow=head,*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *prev=NULL,*curr=slow->next,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    struct ListNode *p1=head,*p2=prev;
    bool palindrome=true;
    while(p2!=NULL){
        if(p1->val!=p2->val){
            palindrome=false;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return palindrome;
}
