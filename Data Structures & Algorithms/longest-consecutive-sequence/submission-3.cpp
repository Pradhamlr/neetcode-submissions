class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;

        for(auto it: nums) {
            us.insert(it);
        }

        int answer = 0;

        for(auto it: nums) {
            if(!us.count(it - 1)) {
                int start = it;
                int len = 1;

                while(us.count(start + 1)) {
                    len++;
                    start++;
                }

                answer = max(len, answer);
            }
        }

        return answer;
    }
};
