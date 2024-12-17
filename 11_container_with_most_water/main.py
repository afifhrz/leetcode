from solution import Solution
import time
start_time = time.time()

create = Solution()
height = [1,8,6,2,5,4,8,3,7]
print(create.maxArea(height))

print("--- %s seconds ---" % (time.time() - start_time))