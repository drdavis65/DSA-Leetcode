class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        currSum = 0
        minLen = float('inf')
        L = 0
        for R in range(len(nums)):
            currSum += nums[R]
            while currSum >= target:
                minLen = min(minLen, R - L + 1)
                currSum -= nums[L]
                L += 1
        if minLen == float('inf'):
            return 0
        return minLen
