
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
