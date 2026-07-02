class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int l = 0;

        for(int r = 1; r < prices.size(); r++) {
            if(prices[r] < prices[l]) {
                l = r;
                continue;
            }
            profit = max(profit, prices[r] - prices[l]);
        }

        return profit;
    }
};
