class Solution {
public:

    bool kValid(int speed, vector<int>& piles, int h) {
        long long time = 0;

        for(int i = 0; i < piles.size(); i++) {
            time += (piles[i] + speed - 1)/speed;
        }

        if(time <= h) {
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int minSpeed = 0;

        while(l <= r) {
            int mid = (l + r)/2;

            if(kValid(mid, piles, h)) {
                r = mid - 1;
                minSpeed = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return minSpeed;
    }
};
