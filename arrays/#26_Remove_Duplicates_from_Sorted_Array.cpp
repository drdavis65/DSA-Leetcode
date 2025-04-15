// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int currTok = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(currTok != nums[i]) {
                currTok = nums[i];
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
