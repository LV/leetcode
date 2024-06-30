/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        if(num >= 0 && num <= 9) return num;
        string n = to_string(num);
        int result = 0;
        for(int i=0; i<n.size(); i++) result += n[i] - '0';
        return addDigits(result);
    }
};
// @lc code=end

