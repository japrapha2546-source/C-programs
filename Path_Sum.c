Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) 
      return false;
    if (!root->left && !root->right)
        return targetSum == root->val;
    int remaining = targetSum - root->val;
    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}
