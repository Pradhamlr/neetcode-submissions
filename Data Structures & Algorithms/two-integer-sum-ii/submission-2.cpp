class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> answer;

        while(l < r) {
            int sum = numbers[l] + numbers[r];

            if(sum == target) {
                answer.push_back(l + 1);
                answer.push_back(r + 1);
                break;
            }

            else if(sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return answer;
    }
};
