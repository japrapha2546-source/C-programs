Example 1:
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]

Example 2:
Input: head = [7]
Output: [7]

int gcd(int a,int b){
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode* curr=head;
    while(curr && curr->next){
        int val=gcd(curr->val,curr->next->val);
        struct ListNode* node=malloc(sizeof(struct ListNode));
        node->val=val;
        node->next=curr->next;
        curr->next=node;
        curr=node->next;
    }
    return head;
}
