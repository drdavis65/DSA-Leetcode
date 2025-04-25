# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = []
        if not root:
            return levels
        
        level = 0
        queue = deque(
            [
                root,
            ]
        )
        while queue:
            levels.append([])

            level_length = len(queue)

            for _ in range(level_length): # ensure popping only nodes in level
                node = queue.popleft() # remove from queue

                levels[level].append(node.val) # append to list within levels

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            level += 1 # increase level
        
        return levels
