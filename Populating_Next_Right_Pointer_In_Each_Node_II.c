Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]

Example 2:
Input: root = []
Output: []

struct Node* connect(struct Node* root){
    if(!root) 
        return NULL;
    struct Node* leftmost=root;
    while(leftmost){
        struct Node* curr=leftmost;
        struct Node* prev=NULL;
        leftmost=NULL;

        while(curr){
            if(curr->left){
                if(prev) 
                    prev->next=curr->left;
                else 
                    leftmost=curr->left;
                prev=curr->left;
            }
            if(curr->right){
                if(prev) 
                    prev->next=curr->right;
                else 
                    leftmost=curr->right;
                prev=curr->right;
            }
            curr=curr->next;
        }
    }
    return root;
}
