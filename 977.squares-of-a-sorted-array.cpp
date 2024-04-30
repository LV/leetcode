// @leet start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = 0;
        while(nums[index] < 0) index++;

        // split lists
        vector<int> negativeNumbers(nums.begin(), nums.begin()+index);
        vector<int> nonNegativeNumbers(nums.begin()+index, nums.end());

        transform(negativeNumbers.begin(), negativeNumbers.end(), negativeNumbers.begin(), [](int x) {
            return x*x;
        });

        transform(nonNegativeNumbers.begin(), nonNegativeNumbers.end(), nonNegativeNumbers.begin(), [](int x) {
            return x*x;
        });

        // attach lists
        int i = negativeNumbers.size()-1;
        int j = 0;
        const int max = nonNegativeNumbers.size();
        vector<int> result;

        while(i>=0 && j<max) {
            if(nonNegativeNumbers[j] < negativeNumbers[i]) {
                result.push_back(nonNegativeNumbers[j]);
                j++;
            } else {
                result.push_back(negativeNumbers[i]);
                i--;
            }
        }

        if(i<0) result.insert(result.end(), nonNegativeNumbers.begin(), nonNegativeNumbers.end());
        else result.insert(result.end(), negativeNumbers.begin(), negativeNumbers.end());

        return result;
    }
};
// @leet end
