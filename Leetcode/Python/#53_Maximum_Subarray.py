class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum = 0
        maxSum = float('-inf')
        for num in nums:
            if currSum < 0:
                currSum = num
            else:
                currSum += num
            maxSum = max(currSum, maxSum)
        return maxSum
