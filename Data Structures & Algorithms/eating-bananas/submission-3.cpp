class Solution {
public:

    bool isValid(vector<int>& piles, int speed, int h) {
        long long time = 0;

        for(auto it: piles) {
            time += (it + speed - 1)/speed;
        }

        if(time <= h) {
            return true;
        }

        return false;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int minSpeed = INT_MAX;

        while(l <= r) {
            int mid = (l + r)/2;

            if(isValid(piles, mid, h)) {
                minSpeed = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return minSpeed;
    }
};
