# Can be optimized more, currently O(2^n)
class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        arr = []
        
        def helper(i, comb_sum):
            # Base cases
            if comb_sum == target:
                res.append(arr.copy())
                return
            
            if i >= len(nums) or comb_sum > target:
                return
            
            # Choice 1: Include current element (stay at same index for reuse)
            arr.append(nums[i])
            helper(i, comb_sum + nums[i])  # Stay at i to allow reuse
            arr.pop()  # Backtrack
            
            # Choice 2: Skip current element (move to next index)
            helper(i + 1, comb_sum)
        
        helper(0, 0)
        return res
