class Solution {
public:

    vector<vector<bool>> visited;
    int count = 0;

    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1) {
            return;
        }

        if(visited[row][col]) {
            return;
        }

        if(grid[row][col] == '0') {
            return;
        }

        visited[row][col] = true;

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    dfs(r, c, grid);
                }
            }
        }

        return count;
    }
};