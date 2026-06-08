class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<pair<int, int>> st;

        for(int i = 0; i < temperatures.size(); i++) {
            if(st.empty()) {
                st.push({temperatures[i], i});
                continue;
            }
            while(!st.empty() && temperatures[i] > st.top().first) {
                answer[st.top().second] = i - (st.top().second);
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        while(!st.empty()) {
            answer[st.top().second] = 0;
            st.pop();
        }

        return answer;
    }
};
