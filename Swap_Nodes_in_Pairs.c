Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes 
(i.e., only nodes themselves may be changed.) 

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    while(prev->next && prev->next->next){
        struct ListNode* first = prev->next;
        struct ListNode* second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    return dummy.next;
}
