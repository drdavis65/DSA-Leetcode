// Date last reviewed:
// 4/19/2025
// ==================================================
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
  
        std::stack<TreeNode*> stack;
        TreeNode* curr = root;
        while(curr != nullptr || !stack.empty()) {
            while(curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            
            curr = stack.top();
            stack.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        
        return result;
    }
};

// RECURSIVE SOLUTION
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         std::vector<int> result;
  
//         helper(root, result);      
        
//         return result;
//     }

//     void helper(TreeNode* root, vector<int> &result) {
//         if(!root) return;

//         helper(root->left, result);
//         result.push_back(root->val);
//         helper(root->right, result);
//     }
// };
