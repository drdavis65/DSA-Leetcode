class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        myNums = dict()

        for i in range(len(nums)):
            if target - nums[i] in myNums:
                return [i, myNums[target-nums[i]]]
            myNums[nums[i]] = i
        return []
