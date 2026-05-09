class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def __init__(self):
        self.max_diam = 0
    def height(self, root):
        if root == none: 
            return 1 
        left = self.height(root.left)
        right = self.height(root.right)
        self.max_diam = max(self.max_diam, left + right + 1) 
        return left + right 
    def get_diameter(self, root) 
        self.max_diam = 0
        self.height(root)
        return self.max_diam