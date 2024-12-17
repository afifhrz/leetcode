from solution import Solution
import time
start_time = time.time()

create = Solution()
s = -121
print(create.isPalindrome(s))

print("--- %s seconds ---" % (time.time() - start_time))