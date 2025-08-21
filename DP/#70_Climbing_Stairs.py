class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        ways = [1, 2]
        for i in range(2, n):
            ways[i&1] = ways[0] + ways[1]
        return ways[(n-1)&1]
