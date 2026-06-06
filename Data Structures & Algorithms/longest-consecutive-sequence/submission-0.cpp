class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> us;
        int finalLength = 0;
        for(auto it: nums) {
            us.insert(it);
        }
        for(auto it: us) {
            if(us.count(it-1) == 0) {
                int current = it;
                int length = 1;
                while(us.count(current + 1) != 0) {
                    length++;
                    current++;
                }
                finalLength = max(finalLength, length);
            }
        }
        return finalLength;
    }
};
