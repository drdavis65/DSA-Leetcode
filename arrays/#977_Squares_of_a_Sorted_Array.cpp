// Date last reviewed:
// 4/14/2025
// ==================================================
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int i;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) break;
        }
        int j = i;
        int k = i - 1;
        while(j < nums.size() && k >= 0) {
            if(std::abs(nums[k]) < nums[j]) {
                result.push_back(nums[k]*nums[k]);
                k--;
            }else {
                result.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        if(j >= nums.size()) {
            while(k >= 0) {
                result.push_back(nums[k]*nums[k]);
                k--;
            }
        }else {
            while(j < nums.size()) {
                result.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        return result;
    }
};
