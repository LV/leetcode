// @leet start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        unsigned int sumOfSeries = (n*(1+n))/2;
        for(int num:nums) sumOfSeries -= num;
        return sumOfSeries;
    }
};
// @leet end
