class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;
    int tar;
    vector<int> num;

    void dfs(int index, int sum) {
        if(index == num.size()) {
            return;
        }
        if(sum > tar) {
            return;
        }
        if(sum == tar) {
            answer.push_back(subset);
            return;
        }

        subset.push_back(num[index]);
        dfs(index, num[index] + sum);
        subset.pop_back();
        dfs(index + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        num = nums;
        tar = target;

        dfs(0, 0);

        return answer;
    }
};
