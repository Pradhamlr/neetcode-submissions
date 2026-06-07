class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
       unordered_map<char, int> mpp;
       int maxFreq = 0;
       int ans = 0;

       for(int r = 0; r < s.length(); r++) {
        mpp[s[r]]++;
        maxFreq = max(maxFreq, mpp[s[r]]);

        while((r - l + 1) - maxFreq > k) {
            mpp[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
       }

       return ans;
    }
};
