// @leet start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElem = -1;
        int count = 0;
        for(int i=; i<nums.size(); i++) {
            if(count == 0) {
                majorityElem = nums[i];
                count = 1;
            } else {
                if(majorityElem == nums[i]) count++;
                else count--;
            }
        }
        return majorityElem;
    }
};
// @leet end
