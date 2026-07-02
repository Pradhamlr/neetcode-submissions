class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                if(nums[l] + nums[r] == target) {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }

                    while(l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                }
                else if(nums[l] + nums[r] > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }

        return answer;
    }
};
