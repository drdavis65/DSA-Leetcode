/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    void helper(TreeNode* root, long curr, int& sum) {
        if(!root->left && !root->right) {
            sum += (curr + root->val);
        }
        long newCurr = (curr + root->val) * 10;
        if(root->left) {
            helper(root->left, newCurr, sum);
        }
        if(root->right) {
            helper(root->right, newCurr, sum);
        }
    }
};
