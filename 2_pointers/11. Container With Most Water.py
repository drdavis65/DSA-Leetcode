class Solution:
    def maxArea(self, heights: List[int]) -> int:
        L = 0
        R = len(heights) - 1
        res = 0
        while L < R:
            res = max((R-L) * min(heights[R], heights[L]), res)
            if heights[R] < heights[L]:
                R -= 1
            else:
                L += 1
        return res
