// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int l = 0;
        int r = n - 1;

        for(int i = n - 1; i >= 0; i--) {
            if(std::abs(nums[r]) > std::abs(nums[l])) {
                result[i] = nums[r] * nums[r];
                r--;
            }
            else {
                result[i] = nums[l] * nums[l];
                l++;
            }
        }
        return result;
    }
};
