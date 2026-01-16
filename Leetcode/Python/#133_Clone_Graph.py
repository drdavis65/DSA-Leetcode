"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        oldNew = {}

        def dfs(node):
            if node in oldNew:
                return oldNew[node]
            
            copyNode = Node(node.val)
            oldNew[node] = copyNode
            for n in node.neighbors:
                copyNode.neighbors.append(dfs(n))
            return copyNode

        return dfs(node) if node else None
