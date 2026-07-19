class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;
    vector<int> num;

    void dfs(int index) {
        answer.push_back(subset);

        for(int i = index; i < num.size(); i++) {
            if(i > index && num[i] == num[i - 1]) {
                continue;
            }
            subset.push_back(num[i]);
            dfs(i + 1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        num = nums;
        sort(num.begin(), num.end());
        dfs(0);

        return answer;
    }
};
