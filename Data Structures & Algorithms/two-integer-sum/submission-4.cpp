class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> answer;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(mpp.count(complement)) {
                answer.push_back(mpp[complement]);
                answer.push_back(i);
            }

            mpp[nums[i]] = i;
        }

        return answer;
    }
};
