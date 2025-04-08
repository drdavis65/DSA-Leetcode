class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixMap;
        int sum = 0;
        int max = 0;

        // account for subarray starting at 0
        prefixMap[0] = -1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;

            if(prefixMap.find(sum) != prefixMap.end()) {
                max = std::max(max, i - prefixMap[sum]);
            }
            else {
                prefixMap[sum] = i;
            }
        }
        return max;
    }
};
