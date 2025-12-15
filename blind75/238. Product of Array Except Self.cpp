class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n);
        int prefix = 1;
        for (auto i{0}; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (auto i{n-1}; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};
