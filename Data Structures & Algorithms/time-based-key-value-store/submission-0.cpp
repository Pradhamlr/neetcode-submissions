class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& arr = mpp[key];

        int l = 0;
        int r = arr.size() - 1;
        string ans = "";

        while (l <= r) {
            int mid = (l + r)/2;

            if(arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
