class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> answer;

        for(int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            int a = point[0];
            int b = point[1];
            pq.push({a*a + b*b, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            answer.push_back(points[pq.top().second]);
            pq.pop();
        }

        return answer;
    }
};
