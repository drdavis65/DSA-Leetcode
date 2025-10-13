class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        def dfs(p, q):
            if p == None and q == None:
                return True
            elif p == None or q == None or p.val != q.val:
                return False
            
            return dfs(p.left, q.left) and dfs(p.right, q.right)
        
        return dfs(p, q)
