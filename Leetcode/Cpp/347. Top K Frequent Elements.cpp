class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> umap;
        std::vector<std::vector<int>> freq(nums.size() + 1);
        for(const auto &num : nums) {
            umap[num]++;
        }
        int maxFreq = 0;
        for(const auto & [value, count] : umap) {
            freq[count].push_back(value);
            if(count > maxFreq) maxFreq = count;
        }
        std::vector<int> result;
        for(auto i = maxFreq; i > 0; --i) {
            for(auto n : freq[i]) {
                result.push_back(n);
                if(static_cast<int>(result.size()) == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
