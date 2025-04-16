class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> set;
        
        int max1, max2, max3;
        max1 = max2 = max3 = INT_MIN;
        for(auto num : nums) {
            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            if(num > max2 && num < max1) {
                max3 = max2;
                max2 = num;
            }
            if(num > max3 && num < max2) {
                max3 = num;
            }
            set.insert(num);
        }
        if(set.size() >= 3) return max3;
        return max1;
        
    }
};
