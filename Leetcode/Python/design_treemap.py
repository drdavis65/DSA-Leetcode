class TreeNode:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.left = None
        self.right = None

class TreeMap:
    def __init__(self):
        self.root = None

    def insert(self, key: int, val: int) -> None:
        newNode = TreeNode(key, val)
        if not self.root:
            self.root = newNode
            return
        curr = self.root
        while True:
            if key < curr.key:
                if not curr.left:
                    curr.left = newNode
                curr = curr.left
            elif key > curr.key:
                if not curr.right:
                    curr.right = newNode
                curr = curr.right
            else:
                curr.val = val
                return

    def get(self, key: int) -> int:
        curr = self.root
        while curr:
            if key > curr.key:
                curr = curr.right
            elif key < curr.key:
                curr = curr.left
            else:
                return curr.val
        return -1

    def getMin(self) -> int:
        curr = self.root
        while curr and curr.left:
            curr = curr.left
        if curr:
            return curr.val
        return -1

    def getMax(self) -> int:
        curr = self.root
        while curr and curr.right:
            curr = curr.right
        if curr:
            return curr.val
        return -1

    def findMin(self, node: TreeNode) -> TreeNode:
        while node and node.left:
            node = node.left
        return node

    def removeHelper(self, curr: TreeNode, key: int) -> TreeNode:
        if not curr:
            return None
        if key > curr.key:
            curr.right = self.removeHelper(curr.right, key)
        elif key < curr.key:
            curr.left = self.removeHelper(curr.left, key)
        else:
            if not curr.left:
                return curr.right
            if not curr.right:
                return curr.left
            else:
                minTemp = self.findMin(curr.right)
                curr.key = minTemp.key
                curr.val = minTemp.val
                curr.right = self.removeHelper(curr.right, minTemp.key)
        return curr

    def remove(self, key: int) -> None:
        self.root = self.removeHelper(self.root, key)

    def dfsKey(self, root: TreeNode, nodes: List[int]):
        if not root:
            return
        self.dfsKey(root.left, nodes)
        nodes.append(root.key)
        self.dfsKey(root.right, nodes)

    def getInorderKeys(self) -> List[int]:
        res = []
        self.dfsKey(self.root, res)
        return res

