class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(board.size());
        vector<unordered_set<int>> coloumn(board.size());
        vector<unordered_set<int>> grid(board.size());

        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board.size(); c++) {
                char number = board[r][c];
                if(number == '.') {
                    continue;
                }
                if(row[r].count(number)) {
                    return false;
                }
                if(coloumn[c].count(number)){
                    return false;
                }
                int box = (r/3)*3 + (c/3);
                if(grid[box].count(number)) {
                    return false;
                }

                grid[box].insert(number);
                row[r].insert(number);
                coloumn[c].insert(number);
            }
        }

        return true;
    }
};
