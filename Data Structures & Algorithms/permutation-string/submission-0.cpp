class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         unordered_map<char, int> mpp;
        unordered_map<char, int> mpp1;
        if(s1.length() > s2.length()) {
            return false;
        }
        for(auto it: s1) {
            mpp[it]++;
        }

        for(int i = 0; i < s1.length(); i++) {
            mpp1[s2[i]]++;
        }

        if(mpp == mpp1) {
            return true;
        } 

        for(int r = s1.length(); r < s2.length(); r++) {
            mpp1[s2[r]]++;
            mpp1[s2[r - s1.length()]]--;

            if(mpp1[s2[r - s1.length()]] == 0) {
                mpp1.erase(s2[r - s1.length()]);
            }

            if(mpp == mpp1) {
                return true;
            }
        }

        return false;
    }
};
