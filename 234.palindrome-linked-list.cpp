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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* prev = head;
        head = head->next;
        prev->next = NULL;
        ListNode* next;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    vector<int> linkedListToVec(ListNode* head) {
        if(!head) return {};
        vector<int> results;
        while(head) {
            results.push_back(head->val);
            head = head->next;
        }
        return results;
    }

    bool isSameVec(vector<int> p, vector<int> q) {
        if(p.size() == 0 && q.size() == 0) return true;
        if(p.size() != q.size()) return false;
        for(int i=0; i<p.size(); i++) if(p[i] != q[i]) return false;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        vector<int> normVec = linkedListToVec(head);
        ListNode* reversed = reverseList(head);
        vector<int> revVec = linkedListToVec(reversed);
        return isSameVec(normVec, revVec);
    }
};
// @leet end
