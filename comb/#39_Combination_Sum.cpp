class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, curr, res, 0);
        return res;
    }
    void helper(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int i) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        for(int j = i; j < candidates.size(); j++) {
            curr.push_back(candidates[j]);
            helper(candidates, target - candidates[j], curr, res, j);
            curr.pop_back();
        }

    }
};
