class Solution:
    def maxArea(self, heights: List[int]) -> int:
        L = 0
        R = len(heights) - 1
        res = 0
        area = 0
        while L < R:
            if heights[R] < heights[L]:
                area = (R-L)*heights[R]
                R -= 1
            else:
                area = (R-L)*heights[L]
                L += 1
            res = max(area, res)
        return res
