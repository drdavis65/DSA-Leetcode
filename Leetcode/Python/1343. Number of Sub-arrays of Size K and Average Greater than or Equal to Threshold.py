class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        target = threshold * k
        count = 0
        currSum = sum(arr[:k-1])
        for r in range(k-1, len(arr)):
            currSum += arr[r]
            count += currSum >= target    # bool adds as 0/1
            currSum -= arr[r - k + 1]
        return count
