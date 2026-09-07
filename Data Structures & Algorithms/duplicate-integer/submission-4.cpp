class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> us;

        for(int num: nums) {
            if(us.contains(num)) {
                return true;
            }

            us.insert(num);
        }

        return false;
    }
};