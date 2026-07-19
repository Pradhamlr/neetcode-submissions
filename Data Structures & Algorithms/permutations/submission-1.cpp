class Solution {
public:

    vector<int> subset;
    vector<vector<int>> answer;
    vector<int> num;
    vector<bool> used;

    void dfs() {
        if(subset.size() == num.size()) {
            answer.push_back(subset);
            return;
        }

        for(int i = 0; i < num.size(); i++) {
            if(used[i]) {
                continue;
            }
            subset.push_back(num[i]);
            used[i] = true;
            dfs();
            used[i] = false;
            subset.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        num = nums;
        used = vector<bool>(num.size(), false);
        dfs();

        return answer;
    }
};
