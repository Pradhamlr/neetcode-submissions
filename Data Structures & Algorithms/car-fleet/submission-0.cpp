class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vr;
        stack<double> st;
        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            vr.push_back({position[i], time});
        }

        sort(vr.rbegin(), vr.rend());

        for(auto it: vr) {
            cout << it.first << " " << it.second << " ";
            if(st.empty()) {
                st.push(it.second);
                continue;
            }
            if(it.second <= st.top()) {
                continue;
            }
            st.push(it.second);
        }


        return st.size();
    }
};
