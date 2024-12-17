from solution import Solution
import time
start_time = time.time()

create = Solution()
nums = ["01","10"]
print(create.findDifferentBinaryString(nums))

print("--- %s seconds ---" % (time.time() - start_time))