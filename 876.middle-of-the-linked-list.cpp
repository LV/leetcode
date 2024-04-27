// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head) {
        if(!head) return 0;
        return 1 + length(head->next);
    }

    ListNode* middleNode(ListNode* head) {
        int length = length(head);
        for(int i=0; i<length/2; i++) head = head->next;
        return head;
    }
};
// @leet end
