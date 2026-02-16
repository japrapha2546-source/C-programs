Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(!head) 
        return NULL;
    if(!head->next){
        struct TreeNode* node=malloc(sizeof(struct TreeNode));
        node->val=head->val;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    struct ListNode *prev=NULL;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    struct TreeNode* root=malloc(sizeof(struct TreeNode));
    root->val=slow->val;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(slow->next);
    return root;
}
