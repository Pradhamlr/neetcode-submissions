class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maximum = 0;
        while(l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            cout << area << " ";
            maximum = max(area, maximum);
            cout << maximum << " ";
            if(heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maximum;
    }
};
