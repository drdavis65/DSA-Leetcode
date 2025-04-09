// Date last reviewed:
// 4/9/2025
// =======================================================
class Solution {
public:
    int climbStairs(int n) {
        int steps[4];
        steps[1] = 1;
        steps[2] = 2;
        for(int i = 3; i < n+1; i++) {
            steps[i&3] = steps[(i-1)&3] + steps[(i-2)&3];
        }
        return steps[n&3];
    }
};
