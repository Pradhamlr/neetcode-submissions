class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r) {
            int length = r - l;
            int height = min(heights[l], heights[r]);

            maxArea = max(maxArea, length * height);

            if(heights[l] <= heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxArea;
    }
};
