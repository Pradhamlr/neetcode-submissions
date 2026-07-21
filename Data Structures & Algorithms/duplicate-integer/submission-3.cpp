class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;

        for(auto it: nums) {
            if(us.count(it)) {
                return true;
            }

            us.insert(it);
        }

        return false;
    }
};