// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int oddPtr = 0;
        int evenPtr = nums.size() - 1;
        while(oddPtr < evenPtr) {
            if(nums[oddPtr] % 2 > nums[evenPtr] % 2) { 
                std::swap(nums[oddPtr], nums[evenPtr]); 
            }

            if(nums[oddPtr] % 2 == 0) oddPtr++;
            if(nums[evenPtr] % 2 == 1) evenPtr--;
        }
        return nums;
    }
};
