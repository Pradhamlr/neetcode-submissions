class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        bool flag = true;

        while(l <= r) {
            if(isalnum(s[l]) == false) {
                l++;
                continue;
            }
            if(isalnum(s[r]) == false) {
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                flag = false;
                break;
            }
            l++;
            r--;
        }

        return flag;
    }
};
