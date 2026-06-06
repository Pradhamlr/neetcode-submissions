class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> mpp;
        if(s.length() != t.length()) {
            return false;
        }
        for(auto it: s) {
            mpp[it] = mpp[it] + 1;
            cout << mpp[it] << " ";
        }
        for(auto it: t) {
            mpp[it] = mpp[it] - 1;
            cout << mpp[it] << " ";
        }
        for(auto it: mpp) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};
