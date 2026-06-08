class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int index = -1;

        while(l <= r) {
             
            int mid = l + (r - l)/2;

            if(nums[mid] == target) {
                index = mid;
                break;
            }

            else if(nums[mid] < target) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        return index; 
    }
};
