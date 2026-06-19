class Solution {
public:


    vector<int> subset;
    vector<vector<int>> answer;
    vector<bool> used;

    void dfs(vector<int> nums) {

        if(subset.size() == nums.size()) {
            answer.push_back(subset);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) {
                continue;
            }

            subset.push_back(nums[i]);
            used[i] = true;
            dfs(nums);
            used[i] = false;
            subset.pop_back();
        }
    } 

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        dfs(nums);

        return answer;
    }
};