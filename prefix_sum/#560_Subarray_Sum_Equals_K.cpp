// Date last reviewed:
// 4/8/2025
// ==================================================
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        int sum = 0;
        map[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(map.find(sum - k) != map.end()) {
                count += map[sum - k];
            }
            if(map.find(sum) != map.end()) {
                map[sum] += 1;
            }else {
                map[sum] = 1;
            }
        }
        return count;
    }
};
