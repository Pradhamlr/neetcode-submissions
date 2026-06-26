class Solution {
public:

    int robber(vector<int>& nums, int start, int end) {
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i < end; i++) {
            int curr = max(prev1, nums[i] + prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        if(n == 2) {
            return max(nums[0], nums[1]);
        }

        int case1 = robber(nums, 0, n - 1);
        int case2 = robber(nums, 1, n);

        return max(case1, case2);
    }
};