class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int searchSpace = (nums1.size() + nums2.size() + 1)/2;

        int l = 0;
        int r = n;

        while(l <= r) {
            int i = (l + r)/2;

            int j = searchSpace - i;

            int aleft = (i==0) ? INT_MIN: nums1[i-1];
            int aright = (i==n) ? INT_MAX: nums1[i];
            int bleft = (j==0) ? INT_MIN: nums2[j-1];
            int bright = (j==m) ? INT_MAX: nums2[j];

            if(aleft <= bright && bleft <= aright) {
                if((n + m)%2 != 0) {
                    return max(aleft, bleft);
                }
                else {
                    return (max(aleft, bleft) + min(aright, bright))/2.0;
                }
            }

            else if(aleft > bright) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};
