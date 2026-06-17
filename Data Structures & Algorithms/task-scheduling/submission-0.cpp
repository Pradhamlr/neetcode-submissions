class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        priority_queue<int> pq;
        queue<pair<int, int>> cooldown;

        for(auto &it: tasks) {
            mpp[it]++;
        }

        for(auto &it:mpp) {
            pq.push(it.second);
        }

        int time = 0;
        while(!pq.empty() || !cooldown.empty()) {
            time++;
            
            while(!cooldown.empty() && cooldown.front().second <= time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if(!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if(freq > 0) {
                    cooldown.push({freq, time + n + 1});
                }
            }
        }

        return time;
    }
};
