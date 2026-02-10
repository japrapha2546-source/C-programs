You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

int numComponents(struct ListNode* head,int* nums,int numsSize){
    int n=numsSize;
    int set[10000]={0};
    for(int i=0;i<numsSize;i++) 
       set[nums[i]]=1;
    int count=0;
    int inComp=0;
    while(head!=NULL){
        if(set[head->val]){
            if(!inComp){
                count++;
                inComp=1;
            }
        }else{
            inComp=0;
        }
        head=head->next;
    }
    return count;
}
