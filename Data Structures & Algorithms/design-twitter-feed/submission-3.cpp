class Twitter {
public:

    int time = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweet;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweet[userId].push_back({time, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> answer;
        for(auto &it: tweet[userId]) {
            pq.push(it);
            if(pq.size() > 10) {
                pq.pop();
            }
        }

        for(auto &it: follows[userId]) {
            for(auto &tweets: tweet[it]) {
                pq.push(tweets);
                if(pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        while(!pq.empty()) {
            int topId = pq.top().second;
            pq.pop();
            answer.push_back(topId);
        }

        reverse(answer.begin(), answer.end());

        
        return answer;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */