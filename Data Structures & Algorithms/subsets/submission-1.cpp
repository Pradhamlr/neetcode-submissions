class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;
    vector<int> num;

    void dfs(int index) {

        if(index == num.size()) {
            answer.push_back(subset);
            return;
        }

        subset.push_back(num[index]);
        dfs(index + 1);
        subset.pop_back();
        dfs(index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        num = nums;
        dfs(0);

        return answer;
    }
};
