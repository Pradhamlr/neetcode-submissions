class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        unordered_map<char, int> mpp1;

        for(auto it: t) {
            mpp[it]++;
        }

        int need = mpp.size();
        int have = 0;

        int l = 0;
        int length = INT_MAX;
        int start;

        for(int r = 0; r < s.length(); r++) {
            mpp1[s[r]]++;

            if(mpp.count(s[r]) == true && mpp[s[r]] == mpp1[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < length) {
                    length = r - l + 1;
                    start = l;
                }

                mpp1[s[l]]--;

                if(mpp.count(s[l]) && mpp1[s[l]] < mpp[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        if(length == INT_MAX) {
            return "";
        }

        return s.substr(start, length); 
    }
};
