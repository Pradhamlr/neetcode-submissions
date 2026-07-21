class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int maxLen = 0;

        int l = 0;

        for(int r = 0; r < s.length(); r++) {
            while(us.count(s[r])) {
                us.erase(s[l]);
                l++;
            }

            us.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
