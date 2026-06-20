class Solution {
public:

    vector<vector<string>> answer;
    vector<string> subset;

    bool isPalindrome(string& s, int l, int r) {

        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(int index, string s) {
        if(index == s.size()) {
            answer.push_back(subset); 
            return;
        }

        for(int end = index; end < s.size(); end++) {
            string part = s.substr(index, end - index + 1);

            if(isPalindrome(s, index, end)) {
                subset.push_back(part);
                dfs(end + 1, s);
                subset.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);

        return answer;
    }
};