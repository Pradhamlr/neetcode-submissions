class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;

        int l = 0;

        for(int r = 1; r < prices.size(); r++) {
            if(prices[l] > prices[r]) {
                l = r;
                continue;
            }
            answer = max(answer, prices[r] - prices[l]);
        }

        return answer;
    }
};
