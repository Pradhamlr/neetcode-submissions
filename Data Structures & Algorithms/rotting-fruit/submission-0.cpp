class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) {
            return fresh;
        }
        int mins = 0;

        while(!q.empty() && fresh > 0) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for(auto [dr, dc]: dirs) {
                    int nr = dr + r;
                    int nc = dc + c;
                    if(nr < 0 || nc < 0 || nr > rows - 1 || nc > cols - 1) {
                        continue;
                    }
                    if(grid[nr][nc] != 1) {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }

            mins++;
        }

        return (fresh == 0)?mins: -1;
    }
};