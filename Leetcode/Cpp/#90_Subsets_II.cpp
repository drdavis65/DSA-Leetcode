class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        size_t n = nums.size();
        int maxSets = 1 << n;
        std::set<std::string> seen;
        for(int i = 0; i < maxSets; i++) {
            std::vector<int> curr;
            std::string curr_str = "";
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    curr.push_back(nums[j]);
                    curr_str += std::to_string(nums[j]);
                }
            }
            if(seen.find(curr_str) == seen.end()) {
                seen.insert(curr_str);
                result.push_back(curr);
            }
        }
        return result;
    }
};
