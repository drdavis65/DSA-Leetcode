// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int swp_idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                std::swap(nums[swp_idx++], nums[i]);
            }
        }
        
    }
};

// INITIAL SOLUTION... ALMOST OPTIMAL
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size();
//         int wr_ptr = 0;
//         int zero_count = 0;
        
//         for(int i = 0; i < n; i++) {
//             if(nums[i] == 0) {
//                 zero_count++;
//             }else{
//                 nums[wr_ptr++] = nums[i];
//             }
//         }
        
//         for(int j = n - zero_count; j < n; j++) {
//             nums[j] = 0;
//         }
        
//     }
// };
