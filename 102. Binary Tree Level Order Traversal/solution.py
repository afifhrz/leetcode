# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return root
        res = []
        queue = [root]
        while True:
            temp = []
            node_collect = []
            while queue:
                node = queue.pop(0)
                temp.append(node.val)
                node_collect.append(node)
            for item in node_collect:
                if item.left:
                    queue.append(item.left)
                if item.right:
                    queue.append(item.right)
            # print(queue)
            res.append(temp)
            if not queue:
                return res            