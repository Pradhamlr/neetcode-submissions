class Solution {
public:

    vector<vector<int>> answer;
    vector<int> subset;
    vector<int> numbers;

    void dfs(int index) {
        if(index == numbers.size()) {
            answer.push_back(subset);
            return;
        }
        subset.push_back(numbers[index]);
        dfs(index + 1);
        subset.pop_back();

        dfs(index + 1);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        numbers = nums;
        dfs(0);
        return answer;
    }
};