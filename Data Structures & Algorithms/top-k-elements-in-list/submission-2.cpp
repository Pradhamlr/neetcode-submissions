class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> answer;

        for(auto &it: nums) {
            mpp[it]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &it: mpp) {
            pq.push({it.second, it.first});
        }

        int i = 0;
        while (i < k) {
            answer.push_back(pq.top().second);
            pq.pop();
            i++;
        }

        return answer;
    }
};
