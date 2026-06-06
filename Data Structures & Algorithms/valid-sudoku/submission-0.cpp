class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> mix(9);

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                char num = board[r][c];
                if(num == '.') {
                    continue;
                }
                int newR = r/3;
                int newC = c/3;
                int newI = newR*3 + newC;
                if(mix[newI].count(num) == 1) {
                    return false;
                }
                if(cols[c].count(num) == 1) {
                    return false;
                }
                if(rows[r].count(num) == 1) {
                    return false;
                }
                cols[c].insert(num);
                rows[r].insert(num);
                mix[newI].insert(num);
            }
        }

        return true;
    }
};
