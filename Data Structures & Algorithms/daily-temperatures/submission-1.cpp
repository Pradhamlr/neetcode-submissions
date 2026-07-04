class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                answer[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
            
        }

        return answer;
    }
};
