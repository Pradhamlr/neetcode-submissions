class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> answer;

        for(int r = 0; r < nums.size(); r++) {
            while(!dq.empty() && nums[r] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);

            while(!dq.empty() && dq.front() <= r - k) {
                dq.pop_front();
            }

            if(r >= k - 1) {
                answer.push_back(nums[dq.front()]);
            }
        }

        return answer;
    }
};
