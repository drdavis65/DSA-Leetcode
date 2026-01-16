class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1) {
                    maxArea = std::max(maxArea, markAndCount(grid, r, c));
                }
            }
        }
        return maxArea;
        
    }

    int markAndCount(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return 0;
        }
        if(grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        return 1 + markAndCount(grid, r + 1, c) + markAndCount(grid, r - 1, c) + markAndCount(grid, r, c + 1) + markAndCount(grid, r, c - 1);
    }
};
