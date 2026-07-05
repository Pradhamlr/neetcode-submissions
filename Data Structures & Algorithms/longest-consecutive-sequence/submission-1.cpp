class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int answer = 0;

        for(auto &it: nums) {
            us.insert(it);
        }

        for(auto &it: nums) {
            while(us.count(it - 1) == true) {
                it = it - 1;
            }
            int start = it;
            int length = 1;
            while(us.count(start + 1) == true) {
                start = start + 1;
                length++;
            }

            answer = max(answer, length);
        }

        return answer;
    }
};
