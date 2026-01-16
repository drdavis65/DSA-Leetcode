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
    void helper(TreeNode* root, int curr, int& sum) {
        if(!root->left && !root->right) {
            sum += (curr + root->val);
        }
        int newCurr = (curr + root->val);
        if(root->left) {
            helper(root->left, newCurr * 10, sum);
        }
        if(root->right) {
            helper(root->right, newCurr * 10, sum);
        }
    }
};
