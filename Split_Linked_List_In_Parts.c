Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
Return an array of the k parts.

#include <stdlib.h>

struct ListNode** splitListToParts(struct ListNode* head,int k,int* returnSize){
    struct ListNode** res=(struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    *returnSize=k;

    int len=0;
    struct ListNode* cur=head;
    while(cur){
        len++;
        cur=cur->next;
    }

    int part_len=len/k;
    int extra=len%k;

    cur=head;
    for(int i=0;i<k;i++){
        res[i]=cur;
        int curr_size=part_len+(i<extra?1:0);
        for(int j=0;j<curr_size-1;j++){
            if(cur) cur=cur->next;
        }
        if(cur){
            struct ListNode* next=cur->next;
            cur->next=NULL;
            cur=next;
        }
    }
    return res;
}


 
