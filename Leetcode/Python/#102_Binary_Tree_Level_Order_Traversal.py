# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        if root:
            q.append(root)
        res = []
        while(len(q) > 0):
            level_len = len(q)
            level = []
            for i in range(level_len):
                curr = q.popleft()
                level.append(curr.val)
                print(f"{curr.val} ", end="")
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            res.append(level)
            print()
        return res

