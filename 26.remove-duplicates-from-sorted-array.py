#
# @lc app=leetcode id=26 lang=python3
#
# [26] Remove Duplicates from Sorted Array
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i: int = 1
        while i < len(nums):
            if nums[i] == nums[i-1]:
                del nums[i]
            else:
                i += 1
        
        return len(nums)
        
# @lc code=end

