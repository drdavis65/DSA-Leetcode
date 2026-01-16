class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_map<int, int> umap;
        // umap.reserve(nums.size());
        int result = 0;
        for(const auto& num : nums) {
            // Skip duplicates
            if(!umap[num]) {
                // Add -1 and +1 entries to find sequence length
                // (filling a gap or adding to sequence)
                int update = umap[num - 1] + umap[num + 1] + 1;
                // New entry
                umap[num] = update;
                // Update min. of sequence
                umap[num - umap[num - 1]] = update;
                // Update max. of sequence
                umap[num + umap[num + 1]] = update;
                result = std::max(result, update);
            }
        }
        return result;
    }
};
