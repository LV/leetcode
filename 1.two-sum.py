#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d: dict[int, int] = {}
        for i in range(len(nums)):
            if nums[i] in d and nums[i]*2==target:
                return [d[nums[i]], i]
            d[nums[i]] = i
        
        for num in nums:
            if (num in d) and (target-num in d) and (num != target-num):
                return [d[num], d[target-num]]
        
# @lc code=end

