class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        right = 0
        while right < len(nums):
            if nums[right] == 0:
                left = right
                while right < len(nums) and nums[right] == 0:
                    right += 1
                n = right - left
                subarrays = (n * (n+1)) // 2
                count += subarrays
            right += 1
        return count
        
        
