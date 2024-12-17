class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height) - 1
        area = 0

        while left <=right:
            area = max(area,(right - left) * min(height[left], height[right]))
            # two pointer argument: move the shorter one, because this is the best area the shorter one can get, so don't need to consider this shorter one in future options 
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1 

        return area