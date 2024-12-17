class Solution(object):
    def __init__(self):
        self.lower_bound = -2**31
        self.upper_bound =  2**31 - 1
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        res= ""
        for x in reversed(str(x)):
            if x == "-":
                res = x + res
            else:
                res +=x
        ans = int(res)
        if ans < self.lower_bound or ans > self.upper_bound:
            return 0
        return ans