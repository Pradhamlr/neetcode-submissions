class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp1;

        for(auto it: s1) {
            mpp1[it]++;
        }

        unordered_map<char, int> mpp2;

        for(int r = 0; r < s1.length(); r++) {
            mpp2[s2[r]]++;
        }

        if(mpp1 == mpp2) {
            return true;
        }

        for(int r = s1.length(); r < s2.length(); r++) {
            mpp2[s2[r]]++;
            int k = r - s1.length();

            mpp2[s2[k]]--;

            if(mpp2[s2[k]] == 0) {
                mpp2.erase(s2[k]);
            }

            if(mpp1 == mpp2) {
                return true;
            }
        }

        return false;
    }
};
