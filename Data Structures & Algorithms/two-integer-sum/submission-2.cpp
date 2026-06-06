class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mpp;
        vector<int> answer;

        int i = 0;
        for(auto it: nums) {
            int complement = target - it;

            if(mpp.count(complement) == 1) {
                answer.push_back(mpp[complement]);
                answer.push_back(i);
                return answer;
            }

            mpp[it] = i;
            i++;
        }
        return answer;
    }
};