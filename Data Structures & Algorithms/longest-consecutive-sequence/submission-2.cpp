class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int answer = 0;

        for(auto &it: nums) {
            us.insert(it);
        }

        for(auto &it: us) {
            if(!us.count(it - 1)) {
                int current = it;
                int length = 1;

                while(us.count(current + 1)) {
                    length++;
                    current = current + 1;
                }
                answer = max(length, answer);
            }
        }

        return answer;
    }
};
