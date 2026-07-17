class Twitter {
public:

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweet;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweet[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> answer;

        for(auto it: tweet[userId]) {
            pq.push(it);
            if(pq.size() > 10) {
                pq.pop();
            }
        }

        for(auto follower: followers[userId]) {
            for(auto it: tweet[follower]) {
                pq.push(it);
                if(pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        while(!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
