// @leet start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 0) return {};

        int index = 0;
        while(index<nums.size() && nums[index]<0) index++;

        transform(nums.begin(), nums.end(), nums.begin(), [](int x){
            return x*x;
        });

        int i = index-1;
        int j = 0;
        vector<int> result;
        while(i>=0 && index+j<nums.size()) {
            if(nums[index+j] < nums[i]) {
                result.push_back(nums[index+j]);
                j++;
            } else {
                result.push_back(nums[i]);
                i--;
            }
        }

        if(i<0) result.insert(result.end(), nums.begin()+index+j, nums.end());
        else {
            while(i>=0) {
                result.push_back(nums[i]);
                i--;
            }
        }

        return result;
    }
};
// @leet end
