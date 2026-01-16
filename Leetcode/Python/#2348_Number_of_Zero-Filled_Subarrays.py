# class Solution:
#     def zeroFilledSubarray(self, nums: List[int]) -> int:
#         count = 0
#         right = 0
#         while right < len(nums):
#             if nums[right] == 0:
#                 left = right
#                 while right < len(nums) and nums[right] == 0:
#                     right += 1
#                 n = right - left
#                 subarrays = (n * (n+1)) // 2
#                 count += subarrays
#             right += 1
#         return count

# Same idea but optimized for less conditional checks
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        res = 0
        for num in nums:
            if num == 0:
                count += 1
            # if num is not zero and res is worth computing!
            elif count > 0:
                res += (count * (count + 1)) // 2
                count = 0
        # in case the last element was a zero
        res += (count * (count + 1)) // 2
        return res
        
        
