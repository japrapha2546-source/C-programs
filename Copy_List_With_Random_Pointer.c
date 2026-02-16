Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

struct Node* copyRandomList(struct Node* head){
    if(!head) 
        return NULL;
    struct Node* curr=head;
    while(curr){
        struct Node* copy=malloc(sizeof(struct Node));
        copy->val=curr->val;
        copy->next=curr->next;
        copy->random=NULL;
        curr->next=copy;
        curr=copy->next;
    }
    curr=head;
    while(curr){
        if(curr->random)
            curr->next->random=curr->random->next;
        curr=curr->next->next;
    }
    curr=head;
    struct Node* dummy=malloc(sizeof(struct Node));
    struct Node* copyCurr=dummy;
    while(curr){
        copyCurr->next=curr->next;
        copyCurr=copyCurr->next;
        curr->next=curr->next->next;
        curr=curr->next;
    }
    struct Node* copiedHead=dummy->next;
    free(dummy);
    return copiedHead;
}
