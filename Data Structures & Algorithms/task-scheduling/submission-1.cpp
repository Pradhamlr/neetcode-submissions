class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        unordered_map<char, int> mpp;

        for(auto it: tasks) {
            mpp[it]++;
        }

        priority_queue<int> pq;

        for(auto it: mpp) {
            pq.push(it.second);
        }

        queue<pair<int, int>> cooldown;

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
