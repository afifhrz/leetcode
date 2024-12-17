# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.check(float('-inf'), root, float('inf'))
    
    def check(self, min, node, max):

        if not node:
            return True
        
        if not (min < node.val < max):
            return False
        
        return self.check(min, node.left, node.val) and self.check(node.val, node.right, max)