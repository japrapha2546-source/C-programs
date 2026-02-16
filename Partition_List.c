Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode beforeDummy, afterDummy;
    struct ListNode *before=&beforeDummy, *after=&afterDummy;
    beforeDummy.next=NULL;
    afterDummy.next=NULL;
    while(head){
        if(head->val<x){
            before->next=head;
            before=head;
        }
        else{
            after->next=head;
            after=head;
        }
        head=head->next;
    }
    after->next=NULL;
    before->next=afterDummy.next;
    return beforeDummy.next;
}
