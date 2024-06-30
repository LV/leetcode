#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1: str = ""
        num2: str = ""
        while l1 is not None:
            num1 += str(l1.val)
            l1 = l1.next
        while l2 is not None:
            num2 += str(l2.val)
            l2 = l2.next
        ans: int = int(num1[::-1]) + int(num2[::-1])
        ln: ListNode = ListNode()
        current = ln  # reference to the first node of ln
        digits: list[str] = list(reversed(str(ans)))
        for i in range(len(digits)):
            current.val = int(digits[i])
            if i != len(digits)-1:
                current.next = ListNode()
                current = current.next
        return ln
        
# @lc code=end

