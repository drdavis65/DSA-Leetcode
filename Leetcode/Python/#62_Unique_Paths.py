class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        prevRow = [1] * n
        for i in range(1,m):
            currRow = [0] * n
            currRow[0] = 1
            for j in range(1,n):
                currRow[j] = currRow[j-1] + prevRow[j]
            prevRow = currRow
        return prevRow[n-1]
