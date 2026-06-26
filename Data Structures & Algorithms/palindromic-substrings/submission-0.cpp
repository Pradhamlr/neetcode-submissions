class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int left = i;
            int right = i;

            while(left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            int left1 = i;
            int right1 = i + 1;

            while(left1 >= 0 && right1 < n && s[left1] == s[right1]) {
                count++;
                left1--;
                right1++;
            }
        }

        return count;
    }
};
