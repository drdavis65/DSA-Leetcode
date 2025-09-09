class Solution:
    def trap(self, height: List[int]) -> int:
        L, R = 0, len(height) - 1
        maxL, maxR = height[L], height[R]
        res = 0
        while L < R:
            if maxL < maxR:
                L += 1
                if height[L] > maxL:
                    maxL = height[L]
                else:
                    res += maxL - height[L]
            else:
                R -= 1
                if height[R] > maxR:
                    maxR = height[R]
                else:
                    res += maxR - height[R]
        return res
