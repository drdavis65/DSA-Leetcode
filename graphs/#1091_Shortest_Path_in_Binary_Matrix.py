class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        SIZE = len(grid)
        if grid[0][0] == 1 or grid[SIZE-1][SIZE-1] == 1:
            return -1
        q = deque()
        grid[0][0] = 1
        q.append((0,0))
        length = 0
        directions = [(0,1), (0,-1), (1,0), (-1,0), (1,1), (-1,-1), (1,-1), (-1,1)]
        while q:
            for _ in range(len(q)):
                r, c = q.popleft()
                if r == SIZE - 1 and c == SIZE -1:
                    return length + 1
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if nr < 0 or nc < 0 or \
                       nr >= SIZE or nc >= SIZE or \
                       grid[nr][nc] == 1:
                       continue
                    grid[nr][nc] = 1
                    q.append((nr,nc))
                    
            length += 1
        return -1
        

