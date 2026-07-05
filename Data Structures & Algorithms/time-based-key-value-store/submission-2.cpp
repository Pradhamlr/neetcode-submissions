class TimeMap {
public:

    unordered_map<string, vector<pair<string, int>>> mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto &arr = mpp[key];
        int l = 0;
        int r = arr.size() - 1;
        string answer = "";

        while(l <= r) {
            int mid = (l + r)/2;

            if(arr[mid].second <= timestamp) {
                answer = arr[mid].first;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return answer;
    }
};
