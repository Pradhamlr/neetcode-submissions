class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, double>> vr(position.size());

        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i])/speed[i];
            vr[i] = {position[i], time};
        }

        sort(vr.rbegin(), vr.rend());

        for(auto it: vr) {
            if(st.empty()) {
                st.push(it.second);
            }
            else if(it.second <= st.top()) {
                continue;
            }
            else {
                st.push(it.second);
            }
        }

        return st.size();
    }
};
