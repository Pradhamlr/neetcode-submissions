class Solution {
public:

    string answer;

    bool dfs(int r, int c, int i, vector<vector<char>>& board, string word) {
        if(i == word.size()) {
            return true;
        }

        if(r < 0 || c < 0 || r > board.size() - 1 || c > board[0].size() - 1) {
            return false;
        }

        if(board[r][c] != word[i]) {
            return false;
        }

        if(board[r][c] == '#') {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(r + 1, c, i + 1, board, word) || dfs(r - 1, c, i + 1, board, word) || dfs(r, c + 1, i + 1, board, word) || dfs(r, c - 1, i + 1, board, word);

        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(i, j , 0, board, word) == true) {
                    return true;
                }
            }
        }

        return false;
        
    }
};