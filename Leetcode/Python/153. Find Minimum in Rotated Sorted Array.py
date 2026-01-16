class Solution:
    def findMin(self, nums: List[int]) -> int:
        start, end = 0, len(nums) - 1
        while start < end:
            mp = start + (end - start) // 2
            if nums[mp] < nums[end]:
                end = mp
            else:
                start = mp + 1   
        return nums[start]
