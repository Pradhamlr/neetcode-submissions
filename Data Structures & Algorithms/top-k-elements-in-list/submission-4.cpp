class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int, int> mpp;

        for(auto it: nums) {
            mpp[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(auto it: mpp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
