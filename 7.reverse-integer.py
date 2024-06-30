#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        rev_str: str = str(x)[::-1]
        if rev_str[-1] == '-':
            return self.bounds(int(rev_str[:-1]) * -1)
        else:
            return self.bounds(int(rev_str))
        
    def bounds(self, x: int) -> int:
        """
        Returns the original number if it is within the 32 bit int range, else returns 0
        """
        return x if x >= -2**31 and x <= (2**31)-1 else 0
# @lc code=end

