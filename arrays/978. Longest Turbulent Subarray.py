class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        neg = -1
        prev = 0
        count = 0
        maxTurb = 0
        for i in range(1, len(arr)):
            diff = arr[i] - arr[i-1]
            sign = 0
            if diff != 0:
                sign = (diff * neg) / abs(diff)
            neg *= -1
            if sign == 0:
                count = 0
            elif sign != prev:
                count = 1
            else:
                count += 1
            maxTurb = max(count, maxTurb)
            prev = sign
        return maxTurb + 1
