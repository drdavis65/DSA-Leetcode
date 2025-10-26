class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        ways = [1, 2]
        for i in range(2, n):
            ways[i&1] = ways[0] + ways[1]
        return ways[(n-1)&1]

class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        dp = [1,2]
        for i in range(2,n+1):
            dp[i%2] = dp[0] + dp[1]
        return dp[(n+1)%2]
