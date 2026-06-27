class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int sum = 0;
        for(auto it: nums) {
            sum += it;
        }
        int n = nums.size();
        int target = sum/2;
        if(sum % 2 != 0) {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        dp[n][0] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(int remaining = 0; remaining <= target; remaining++) {
                bool skip = dp[i + 1][remaining];

                bool take = false;
                if(nums[i] <= remaining) {
                    take = dp[i + 1][remaining - nums[i]];
                }

                dp[i][remaining] = (skip || take);
            }
        }

        return dp[0][target];
    }
};
