class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        s = sum(nums)
        leftsum = 0
        for i in range(len(nums)):
            if leftsum == (s - leftsum - nums[i]):
                return i
            leftsum += nums[i]
        return -1
