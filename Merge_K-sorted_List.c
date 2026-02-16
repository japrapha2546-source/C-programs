Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []  

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode dummy;
    struct ListNode* tail=&dummy;
    dummy.next=NULL;
    while(l1 && l2){
        if(l1->val<=l2->val){
            tail->next=l1;
            l1=l1->next;
        }
        else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    tail->next=l1?l1:l2;
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0) 
      return NULL;
    if(listsSize==1)
      return lists[0];
    int mid=listsSize/2;
    struct ListNode* left=mergeKLists(lists,mid);
    struct ListNode* right=mergeKLists(lists+mid,listsSize-mid);
    return mergeTwoLists(left,right);
}
