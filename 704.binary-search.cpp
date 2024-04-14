// @leet start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;

        int indexLowerBound = 0;
        int indexHigherBound = nums.size()-1;
        int index = indexHigherBound/2;

        while(true) {
            const int indexedNum = nums[index];
            if(indexedNum == target) return index;
            
            // check off by one
            if(indexHigherBound-indexLowerBound == 1) return nums[index+1] == target ? index+1 : -1;

            if(indexedNum < target) indexLowerBound = index;
            else indexHigherBound = index;
            index = indexLowerBound + ((indexHigherBound-indexLowerBound)/2);
        }
        // guaranteed to already return by this point
        //   Searchable area always reduces by half through every iteration;
        //   hence it must terminate with one of the returns
    }
};
// @leet end
