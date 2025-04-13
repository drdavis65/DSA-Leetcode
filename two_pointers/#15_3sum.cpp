

class Solution {
public:
    //sort the array and use binary search to find if missing num exists
    // arr[i] + arr[j] + arr[k] == 0
    // so if -arr[j] - arr[k] == arr[i]
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> seen;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int searchIdx = binarySearch(nums, j+1, nums.size() - 1, -nums[i] - nums[j]);
                if(searchIdx != -1) {
                    vector<int> res = {nums[i], nums[j], nums[searchIdx]};
                    std::sort(res.begin(), res.end());
                    if(seen.find(res) == seen.end()) {
                        result.push_back(res);
                        seen.insert(res);
                    }
                } 
            }
            
        }
        return result;
    }
    int binarySearch(vector<int>& nums, int low, int high, int val) {
        while(low <= high) {
            int mp = low + (high - low) / 2;
            if(nums[mp] == val) {
                return mp;
            }
            else if(val > nums[mp]) {
                low = mp + 1;
            }
            else {
                high = mp - 1;
            }
        }
        return -1;
    }
};
