Given a binary tree root and a linked list with head as the first node. 
Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.

#include <stdbool.h>
#include <stdlib.h>

bool check(struct ListNode* head,struct TreeNode* root){
    if(head==NULL) 
      return true;
    if(root==NULL) 
      return false;
    if(head->val!=root->val) 
      return false;
    return check(head->next,root->left) || check(head->next,root->right);
}

bool isSubPath(struct ListNode* head,struct TreeNode* root){
    if(root==NULL) return false;
    if(check(head,root)) return true;
    return isSubPath(head,root->left) || isSubPath(head,root->right);
}


 
