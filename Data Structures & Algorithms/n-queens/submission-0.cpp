class Solution {
public:

    vector<vector<string>> answer;
    vector<string> board;
    vector<bool> col;
    vector<bool> diognal1;
    vector<bool> diognal2;

    void dfs(int r, int n) {
        if(r == n) {
            answer.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++) {
            if(!col[c] && !diognal1[r + c] && !diognal2[r - c  + n]) {
                board[r][c] = 'Q';
                col[c] = true;
                diognal1[r + c] = true;
                diognal2[r - c + n] = true;
                dfs(r + 1, n);
                col[c] = false;
                diognal1[r + c] = false;
                diognal2[r - c + n] = false;
                board[r][c] = '.';
            }
        }

        
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diognal1 = vector<bool>(2*n, false);
        diognal2 = vector<bool>(2*n, false);

        dfs(0, n);

        return answer;
    }
};