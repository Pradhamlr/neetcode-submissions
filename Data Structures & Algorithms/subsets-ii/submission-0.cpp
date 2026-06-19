class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;

    void dfs(int index, vector<int> nums) {
        if(index > nums.size()) {
            return;
        }
        answer.push_back(subset);

        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            subset.push_back(nums[i]);
            dfs(i + 1, nums);
            subset.pop_back();
        }
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);

        return answer;
    }
};