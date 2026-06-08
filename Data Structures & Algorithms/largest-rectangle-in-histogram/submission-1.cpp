class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++) {
            if(st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int r = i;
                int l;
                if(st.empty()) {
                    l = -1;
                }
                else {
                    l = st.top();
                }
                int width = (r - l - 1);
                int newArea = height * width;
                area = max(area, newArea);
            }
            st.push(i);
        }

        return area;
    }
};
