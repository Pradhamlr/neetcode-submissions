class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            for(string word: wordDict) {
                if(s.substr(i, word.length()) == word && dp[i + word.length()] && (i + word.length() <= n)) {
                    dp[i] = true;
                }
            }
        }

        return dp[0];
    }
};
