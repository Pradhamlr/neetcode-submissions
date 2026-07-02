class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;

        int l = 0;
        int maxFreq = 0;
        int answer = 0;

        for(int r = 0; r < s.length(); r++) {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);

            while(r - l + 1 - maxFreq > k) {
                mpp[s[l]]--;
                l++;
            }

            answer = max(answer, r - l + 1);
        }

        return answer;
    }
};
