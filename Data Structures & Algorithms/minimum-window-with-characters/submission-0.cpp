class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> mpp;
        unordered_map<char, int> mpp1;
        int have = 0;
        int length = INT_MAX;
        int best_start;
        
        for(auto it: t) {
            mpp[it]++;
        }

        int need = mpp.size();
        int l = 0;

        for(int r = 0; r < s.length(); r++) {
            mpp1[s[r]]++;
            if(mpp.count(s[r]) == 1 && mpp[s[r]] == mpp1[s[r]]) {
                have++;
            }
            while(have == need) {              
                if((r - l + 1) < length) {
                    length = r - l + 1;
                    best_start = l;
                }
                mpp1[s[l]]--;
                if(mpp.count(s[l]) == 1 && mpp1[s[l]] < mpp[s[l]]) {
                    have--;
                } 

                l++;
            }
        }
        if(length == INT_MAX) {
            return "";
        }
        
        return s.substr(best_start, length);
    }
};
