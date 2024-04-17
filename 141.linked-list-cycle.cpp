// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        unordered_set<ListNode*> visited;
        while(head) {
            if(head->next == NULL) return false;
            if(auto iter = visited.find(head); iter != visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @leet end

