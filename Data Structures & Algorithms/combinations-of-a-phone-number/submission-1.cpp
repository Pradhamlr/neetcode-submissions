class Solution {
public:

    unordered_map<char, string> mpp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> answer;
    string subset;

    void dfs(int index, string digits) {
        if(subset.size() == digits.size()) {
            answer.push_back(subset);
            return;
        }

        for(char ch: mpp[digits[index]]) {
            subset.push_back(ch);

            dfs(index + 1, digits);

            subset.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        dfs(0, digits);

        return answer;
    }
};