from itertools import product
class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        # leng = len(nums[0])
        # a = product('10', repeat=leng)
        # nums = set(nums)
        # for item in a:
        #     res = "".join(item)
        #     if res not in nums:
        #         return res

        ans = []
        for i, n in enumerate(nums):
            if n[i] == '1':
                ans.append('0')
            else:
                ans.append('1')
        return "".join(ans)