class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;
    int tar;
    vector<int> num;

    void dfs(int index, int sum) {
        
        if(sum > tar) {
            return;
        }
        if(sum == tar) {
            answer.push_back(subset);
            return;
        }
        if(index == num.size()) {
            return;
        }

        for(int i = index; i < num.size(); i++) {
            if(i > index && num[i] == num[i - 1]) {
                continue;
            }
            subset.push_back(num[i]);
            dfs(i + 1, num[i] + sum);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        num = candidates;
        tar = target;
        sort(num.begin(), num.end());

        dfs(0, 0);

        return answer;
    }
};
