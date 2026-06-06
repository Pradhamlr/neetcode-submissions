class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> answer;

        for(auto it: strs) {
            string newIt = it;
            sort(newIt.begin(), newIt.end());
            mpp[newIt].push_back(it);
        }

        for(auto it: mpp) {
            answer.push_back(it.second);
        }

        return answer;
    }
};
