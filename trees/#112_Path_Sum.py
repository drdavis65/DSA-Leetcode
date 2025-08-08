# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def hasPathSumHelp(root, currSum) -> bool:
            if not root:
                return False
            currSum += root.val
            if not root.left and not root.right and currSum == targetSum:
                return True
            if hasPathSumHelp(root.left, currSum):
                return True
            if hasPathSumHelp(root.right, currSum):
                return True
            currSum -= root.val
            return False
        return hasPathSumHelp(root, 0)
