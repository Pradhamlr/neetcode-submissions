class Solution {
public:

    vector<vector<bool>> visited;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if(r < 0 || c < 0 || r > board.size() - 1 || c > board[0].size() - 1) {
            return;
        }
        if(visited[r][c]) {
            return;
        }
        if(board[r][c] == 'X') {
            return;
        }

        visited[r][c] = true;
        board[r][c] = 'T';
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++) {
            dfs(r, 0, board);
        }

        for(int c = 0; c < cols; c++) {
            dfs(0, c, board);
        }

        for(int r = 0; r < rows; r++) {
            dfs(r, cols - 1, board);
        }

        for(int c = 0; c < cols; c++) {
            dfs(rows - 1, c, board);
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};