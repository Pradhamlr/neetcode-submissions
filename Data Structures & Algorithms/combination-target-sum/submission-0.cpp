class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;

    void dfs(int index, vector<int>& candidates, int target, int total_sum) {
        if(total_sum == target) {
            answer.push_back(subset);
            return;
        }
        if(total_sum > target) {
            return;
        }
        if(index == candidates.size()) {
            return;
        }
        subset.push_back(candidates[index]);
        dfs(index, candidates, target, total_sum + candidates[index]);
        subset.pop_back();

        dfs(index + 1, candidates, target, total_sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, candidates, target, 0);

        return answer;
    }
};