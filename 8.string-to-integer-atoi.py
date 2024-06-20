#
# @lc app=leetcode id=8 lang=python3
#
# [8] String to Integer (atoi)
#

# @lc code=start
class Solution:
    def num_in_bounds(self, num: int) -> int:
        if num < (-1 * (2**31)):
            return -1 * (2**31)
        elif num > (2**31)-1:
            return (2**31)-1
        else:
            return num

    def myAtoi(self, s: str) -> int:
        is_pos: bool = True
        num: str = ""

        # remove only leading whitespace
        first_non_whitespace_idx: int = len(s)
        for i in range(len(s)):
            if s[i] != ' ':
                first_non_whitespace_idx = i
                break


        s = s[first_non_whitespace_idx:]

        if len(s) == 0:
            return 0

        if s[0] == "-":
            is_pos = False

        for i in range(len(s)):
            if i == 0 and (s[i] == "-" or s[i] == "+"):
                continue

            if s[i].isdigit():
                num += s[i]

            else:
                break

        if len(num) == 0:
            return 0
        return self.num_in_bounds(int(num)) if is_pos else self.num_in_bounds(-1 * int(num))
# @lc code=end

