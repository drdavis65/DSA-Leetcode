class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        left, right = len(grid[0]), -1
        top, bottom = len(grid), -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    if j < left:
                        left = j
                    if j > right:
                        right = j
                    if i < top:
                        top = i
                    bottom = i
        return (right - left + 1) * (bottom - top + 1)
