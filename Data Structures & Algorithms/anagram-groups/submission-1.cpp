class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> answer;

        for(auto it: strs) {
            string org = it;
            sort(it.begin(), it.end());
            mpp[it].push_back(org);
        }

        for(auto it: mpp) {
            answer.push_back(it.second);
        }

        return answer;
    }
};
