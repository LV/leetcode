// @leet start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        int profit = 0;
        int purchasePrice = prices[0];

        for(int i=1; i<prices.size(); i++) {
            const int priceDiff = prices[i] - purchasePrice;
            if(prices[i] < purchasePrice) purchasePrice = prices[i];
            else if(priceDiff > profit) profit = priceDiff;
        }

        return profit;
    }
};
// @leet end
