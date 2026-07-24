class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        for(int i = 0; i < strs[0].length(); i++) {
            char ref = strs[0][i];

            for(int j = 1; j < strs.size(); j++) {
                if(i > strs[j].length() || ref != strs[j][i]) {
                    return answer;
                }
            }

            answer += ref;
        }

        return answer;
    }
};