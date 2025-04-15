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

// BETTER SOLUTION
// vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> result(n);

//         int left = 0;
//         int right = n - 1;

//         for (int i = n - 1; i >= 0; i--) {
//             int square;
//             if (abs(nums[left]) < abs(nums[right])) {
//                 square = nums[right];
//                 right--;
//             } else {
//                 square = nums[left];
//                 left++;
//             }
//             result[i] = square * square;
//         }
//         return result;
//     }
