from solution import Solution
import time
start_time = time.time()

create = Solution()
root = [2,1,3]
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

node1 = TreeNode(root[1])
node3 = TreeNode(root[2])
ok = TreeNode(root[0], node1, node3)

print(create.isValidBST(ok))

print("--- %s seconds ---" % (time.time() - start_time))