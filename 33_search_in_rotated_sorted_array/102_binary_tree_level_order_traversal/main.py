from solution import Solution
import time
start_time = time.time()
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
create = Solution()

# root = [3,9,20,None,None,15,7]
# node6 = TreeNode(root[6])
# node5 = TreeNode(root[5])
# node2 = TreeNode(root[2], node5, node6)
# node1 = TreeNode(root[1])
# node = TreeNode(root[0], node1, node2)

# node = TreeNode(1)

# node = TreeNode(None)
print(create.levelOrder(node))

print("--- %s seconds ---" % (time.time() - start_time))