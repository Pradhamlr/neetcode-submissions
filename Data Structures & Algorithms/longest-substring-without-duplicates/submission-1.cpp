class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;

        int l = 0;
        int maxLen = 0;

        for(int r = 0; r < s.length(); r++) {
            while(us.count(s[r])) {
                us.erase(s[l]);
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            us.insert(s[r]);
        }

        return maxLen;
    }
};
