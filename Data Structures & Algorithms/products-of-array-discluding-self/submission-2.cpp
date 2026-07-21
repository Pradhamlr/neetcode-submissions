class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> answer(n);

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                prefix[i] = 1;
                continue;
            }

            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                suffix[n - 1] = 1;
                continue;
            }

            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++) {
            answer[i] = prefix[i] * suffix[i];
        }

        return answer;
    }
};
