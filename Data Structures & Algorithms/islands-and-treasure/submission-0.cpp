class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int, int>> q;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc]: dirs) {
                int nr = dr + r;
                int nc = dc + c;
                if(nr < 0 || nc < 0 || nr > rows - 1 || nc > cols - 1) {
                    continue;
                }
                if(grid[nr][nc] != INF) {
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
