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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            int level_size = q.size();
            vector<int> level;
            for(int i = 0; i < level_size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr) {
                    level.push_back(curr->val);
                    cout << curr->val << " ";
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(!level.empty()) {
                res.push_back(level);
            }
            cout << endl;
        }
        return res;
    }
};
