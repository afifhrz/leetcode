from solution import Solution
import time
start_time = time.time()

create = Solution()
nums = [4,5,6,7,0,1,2]
target = 9
print(create.search(nums, target))
print("--- %s seconds ---" % (time.time() - start_time))