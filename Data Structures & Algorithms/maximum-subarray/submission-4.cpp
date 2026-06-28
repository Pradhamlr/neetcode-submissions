class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currentSum = nums[0];
        int answer = nums[0];

        for(int i = 1; i < n; i++) {
            currentSum = max(nums[i], nums[i] + currentSum);
            answer = max(answer, currentSum);
        }

        return answer;
    }
};
