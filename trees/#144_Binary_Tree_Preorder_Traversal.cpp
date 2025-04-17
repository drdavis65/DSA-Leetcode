// Date last reviewed:
// 4/17/2025
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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
  
        std::stack<TreeNode*> stack;
        
        if(root) { 
            stack.push(root); 
        }
        
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            
            result.push_back(curr->val);
            
            if(curr->right) {
                stack.push(curr->right);
            }
            if(curr->left) {
                stack.push(curr->left);
            }
        }
        return result;
    }
};
