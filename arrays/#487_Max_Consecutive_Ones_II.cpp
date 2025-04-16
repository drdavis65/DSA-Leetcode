class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> idxs;
        
        idxs.push_back(-1);
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) idxs.push_back(i);
        }
        
        idxs.push_back(nums.size());
        
        if(idxs.size() == 2) return nums.size();
        
        int max = 0;
        
        for(int j = 1; j < idxs.size()-1; j++) {
            int curr = idxs[j+1] - idxs[j-1] - 1;
            max = curr > max ? curr : max;
        }
        return max;
    }
};
