class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
                unordered_map<int, int> mpp;
        priority_queue<pair<int, int>> pq;
        vector<int> answer;

        for(auto it: nums) {
            mpp[it]++;
        }

        for(auto it: mpp) {
            pq.push({it.second, it.first});
        }
        for(int i = 0; i < k; i++) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        

        return answer;
    }
};
