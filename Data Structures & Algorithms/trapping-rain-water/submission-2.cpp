class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;

        while(l < r) {
            if(height[l] < height[r]) {
                if(height[l] >= maxLeft) {
                    maxLeft = height[l];
                }
                else {
                    water += maxLeft - height[l];
                }
                l++;
            }
            else {
                if(height[r] >= maxRight) {
                    maxRight = height[r];
                }
                else {
                    water += maxRight - height[r];
                }
                r--;
            }
        }

        return water;
    }
};
