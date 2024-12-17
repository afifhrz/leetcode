from solution import Solution
import time
start_time = time.time()
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
create = Solution()
nums = [3,2,1,5,6,4]
k = 2
print(create.findKthLargest(nums, k))

print("--- %s seconds ---" % (time.time() - start_time))