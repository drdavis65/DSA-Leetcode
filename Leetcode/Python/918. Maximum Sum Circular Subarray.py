class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        gMax, gMin = nums[0], nums[0]
        curMax, curMin = float('-inf'), float('inf')
        total = 0
        for num in nums:
            curMax = max(curMax + num, num)
            curMin = min(curMin + num, num)
            gMax = max(curMax, gMax)
            gMin = min(curMin, gMin)
            total += num
        return max(gMax, total - gMin) if gMax > 0 else gMax
