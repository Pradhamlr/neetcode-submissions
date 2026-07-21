class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> box(9);

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                if(board[r][c] == '.') {
                    continue;
                }
                int num = board[r][c];
                if(cols[c].count(num)) {
                    return false;
                }

                if(rows[r].count(num)) {
                    return false;
                }

                int index = (r/3)*3 + c/3;

                if(box[index].count(num)) {
                    return false;
                }

                rows[r].insert(num);
                cols[c].insert(num);
                box[index].insert(num);
            }
        }

        return true;

    }
};
