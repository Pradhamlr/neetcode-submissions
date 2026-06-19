class Solution {
public:

    vector<int> subset;
    vector<vector<int>> answer;
    vector<int> nums;

    void dfs(int index, int currSum, int target) {
        if(target == 0) {
            answer.push_back(subset);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            dfs(i + 1, currSum + nums[i], target - nums[i]);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums = candidates;
        sort(nums.begin(), nums.end());
        dfs(0, 0, target);
        return answer;
    }
};