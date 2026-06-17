class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;

        int l = 0;
        int r = numbers.size() - 1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];

            if(sum == target) {
                answer.push_back(l + 1);
                answer.push_back(r + 1);
                return answer;
            }
            else if(sum > target) {
                r--;
            }
            else {
                l++;
            }
        }
    }
};
