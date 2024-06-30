/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1Seen;
        set<int> nums2Seen;

        for(int i=0; i<nums1.size(); i++) nums1Seen.insert(nums1[i]);
        for(int i=0; i<nums2.size(); i++) nums2Seen.insert(nums2[i]);

        vector<int> result;

        set<int>::iterator idx1 = nums1Seen.begin();
        set<int>::iterator idx2 = nums2Seen.begin();

        while(idx1 != nums1Seen.end() && idx2 != nums2Seen.end()) {
            if(*idx1 == *idx2) {
                result.push_back(*idx1);
                idx1++;
                idx2++;
            }

            if(*idx1 < *idx2) idx1++;
            if(*idx2 < *idx1) idx2++;
        }

        return result;
    }
};
// @lc code=end