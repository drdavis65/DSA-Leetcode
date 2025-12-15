class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> pref(n);
        std::vector<int> suff(n);
        std::vector<int> result(n);
        pref[0] = suff[n-1] = 1;
        for (auto i{1}; i < n; ++i) {
            pref[i] = pref[i-1] * nums[i-1];
        }
        for (auto i{n-2}; i >= 0; --i) {
            suff[i] = suff[i+1] * nums[i+1];
        }
        for (auto i{0}; i < n; ++i) {
            result[i] = pref[i] * suff[i];
        }
        return result;
    }
};
