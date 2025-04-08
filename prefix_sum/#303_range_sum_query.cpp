// Date last reviewed:
// 4/8/2025
// ==================================================
class NumArray {
public:
    vector<int> sumArray;
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;

        int n = nums.size();

        sumArray.resize(n);

        sumArray[0] = nums[0];
        for(int i = 1; i < n; i++) {
            sumArray[i] += sumArray[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sumArray[right];

        return sumArray[right] - sumArray[left-1];
    }
};
