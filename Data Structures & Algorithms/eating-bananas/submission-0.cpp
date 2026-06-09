class Solution {
public:

bool canComplete(vector<int>& piles, int h, int speed) {
        long long hours = 0;;

        for(auto it: piles) {
            hours += (it + speed - 1)/speed;
        }

        if(hours <= h) {
            return true;
        }
        else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans;

        while(l <= r) {
            int mid = (l + r)/2;

            if(canComplete(piles, h, mid) == true) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
