// @leet start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int countZeros = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                countZeros++;
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                i--;
            }
        }
        for(int i=0; i<countZeros; i++) nums.push_back(0);
    }

    // TODO: Make this a little more efficient (e.g. reduce number of erase operations by chained 0s)
};
// @leet end
