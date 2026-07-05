class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int r = i;
                int height = heights[st.top()];
                st.pop();
                int l;
                if(st.empty()) {
                    l = -1;
                }
                else {
                    l = st.top();
                }
                maxArea = max(maxArea, height * (r - l - 1));
            }
            st.push(i);
        }

        return maxArea;
    }
};
