class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;

        for(auto it: s) {
            mpp[it]++;
        }

        for(auto it: t) {
            mpp[it]--;
        }

        for(auto element: mpp) {
            if(element.second != 0) {
                return false;
            }
        }

        return true;
    }
};
