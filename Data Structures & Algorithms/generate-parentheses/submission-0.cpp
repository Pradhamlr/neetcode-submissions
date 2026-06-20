class Solution {
public:

    vector<string> answer;
    string subset;
    int openCount = 0;
    int closeCount = 0;

    void dfs(int n) {
        if(subset.length() == 2*n) {
            answer.push_back(subset);
            return;
        }

        if(openCount < n) {
            subset.push_back('(');
            openCount++;
            dfs(n);
            openCount--;
            subset.pop_back();
        }
        if(closeCount < openCount) {
            subset.push_back(')');
            closeCount++;
            dfs(n);
            closeCount--;
            subset.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n);
        return answer;
    }
};