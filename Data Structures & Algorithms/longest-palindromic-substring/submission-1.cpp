class Solution {
public:
    string longestPalindrome(string s) {
        int start;
        int maxLen = INT_MIN;

        int n = s.length();

        for(int i = 0; i < s.length(); i++) {
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};
