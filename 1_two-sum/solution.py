import heapq

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for index, num in enumerate(nums):
          diff = target - num
          if(diff in dict):
            return [index, dict.get(diff)]
          dict[num] = index
