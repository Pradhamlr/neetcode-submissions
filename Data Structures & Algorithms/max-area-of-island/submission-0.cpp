class Solution {
public:

    vector<vector<bool>> visited;
    int maxCount = 0;

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r > grid.size() - 1 || c > grid[0].size() - 1) {
            return 0;
        }
        if(visited[r][c]) {
            return 0;
        }
        if(grid[r][c] == 0) {
            return 0;
        }

        visited[r][c] = true;

        return 1 + dfs(r + 1, c, grid) + dfs(r - 1, c, grid) + dfs(r, c + 1, grid) + dfs(r, c - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    maxCount = max(maxCount, dfs(i, j, grid));
                }
            }
        }


        return maxCount;
    }
};