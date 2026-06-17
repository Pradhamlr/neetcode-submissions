class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> answer;
        priority_queue<pair<int, int>> pq;

        int i = 0;
        for(auto &it: points) {
            int x = pow(it[0], 2);
            int y = pow(it[1], 2);
            int sum = x + y;
            pq.push({sum, i});
            if(pq.size() > k) {
                pq.pop();
            }
            i++;
        }

        while(!pq.empty()) {
            int index = pq.top().second;
            answer.push_back(points[index]);
            pq.pop();
        }

        return answer;
    }
};