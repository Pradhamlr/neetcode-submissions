class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> answer;

        for(auto element: strs) {
            string sorted = element;
            sort(sorted.begin(), sorted.end());

            mpp[sorted].push_back(element);
        }

        for(auto it: mpp) {
            answer.push_back(it.second);
        }

        return answer;
    }
};
