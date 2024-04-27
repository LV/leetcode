// @leet start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> visited;
        for(int i=0; i<nums.size(); i++) {
            if(auto search = visited.find(nums[i]); search != visited.end()) return true;
            visited.insert(nums[i]);
        }
        return false;
    }
};
// @leet end
