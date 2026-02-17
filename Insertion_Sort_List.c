Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
  
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]


struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head) 
      return head;

    struct ListNode* sorted = head;
    struct ListNode* current = head->next;
    sorted->next = NULL;
    while (current) {
        struct ListNode* next_node = current->next;
        if (current->val < sorted->val) {
            current->next = sorted;
            sorted = current;
        } else {
            struct ListNode* temp = sorted;
            while (temp->next && temp->next->val < current->val) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next_node;
    }
    return sorted;
}
