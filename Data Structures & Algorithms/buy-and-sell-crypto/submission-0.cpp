class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int profit = 0;

        for(int r = 1; r < prices.size(); r++) {
            if(prices[l] > prices[r]) {
                l=r;
                continue;
            }
            int newProfit = prices[r] - prices[l];
            profit = max(newProfit, profit);
        }

        return profit;
        
    }
};
