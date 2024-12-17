class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        while True:
            temp = strs[i][0]
            id = 0
            for i in range(len(strs)):
                strs[i]