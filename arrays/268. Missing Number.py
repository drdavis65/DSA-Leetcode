class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        allSum = sum(nums)
        n = len(nums)
        s = (n * (n+1)) // 2
        return s - allSum
        
