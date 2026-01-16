// Date last reviewed:
// 4/14/2025
// ==================================================
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto num : nums) {
            if(hasEvenDigits(num)) count++;
        }
        return count;
    }
    
    bool hasEvenDigits(int num) {
        if(num == 0) return false;
        int count = 0;
        while(num != 0) {
            num /= 10;
            count++;
        }
        return (count & 1) == 0;
    }
};
