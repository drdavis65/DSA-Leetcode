# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def sameTree(p, q):
            if p == None and q == None:
                return True
            elif p == None or q == None or p.val != q.val:
                return False
            return sameTree(p.left, q.left) and sameTree(p.right, q.right)
        
        def dfs(root, subRoot):
            if root == None:
                return False
            if root.val == subRoot.val:
                if sameTree(root, subRoot):
                    return True
            left = dfs(root.left, subRoot)
            right = dfs(root.right, subRoot)

            return left or right

        return dfs(root, subRoot)
