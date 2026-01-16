class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.prefixMat = matrix
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if row == 0 and col == 0:
                    continue
                if row == 0:
                    self.prefixMat[row][col] += self.prefixMat[row][col-1]
                elif col == 0:
                    self.prefixMat[row][col] += self.prefixMat[row-1][col]
                else:
                    matSum = self.prefixMat[row-1][col] + self.prefixMat[row][col-1] - self.prefixMat[row-1][col-1]
                    self.prefixMat[row][col] += matSum

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        lowerRight = self.prefixMat[row2][col2]
        res = 0
        if row1 == 0 and col1 == 0:
            res = lowerRight
        elif row1 == 0:
            res = lowerRight - self.prefixMat[row2][col1-1]
        elif col1 == 0:
            res = lowerRight - self.prefixMat[row1-1][col2]
        else:
            res = lowerRight - \
            self.prefixMat[row2][col1-1] - \
            self.prefixMat[row1-1][col2] + \
            self.prefixMat[row1-1][col1-1]

        return res


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
