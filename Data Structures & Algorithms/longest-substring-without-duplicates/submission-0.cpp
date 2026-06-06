class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_set<int> us;
        int ans = 0;

        for(int r = 0; r < s.length(); r++) {
            while(us.count(s[r]) == 1) {
                us.erase(s[l]);
                l++;
            }

            us.insert(s[r]);
            ans = max(ans, (int)us.size());
        }

        return ans;
    }
};
