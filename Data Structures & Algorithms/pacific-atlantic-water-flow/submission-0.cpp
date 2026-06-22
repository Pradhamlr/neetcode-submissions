class Solution {
public:

    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> answer;

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        if(r < 0 || c < 0 || r > heights.size() - 1 || c > heights[0].size() - 1) {
            return;
        }
        if(visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        for(auto [dr, dc]: dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr < 0 || nc < 0 || nr > heights.size() - 1 || nc > heights[0].size() - 1) {
                continue;
            }
            if(heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        pacific = vector<vector<bool>>(rows, vector<bool>( cols, false));
        atlantic = vector<vector<bool>>(rows, vector<bool>( cols, false));

        for(int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);
        }

        for(int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific);
        }

        for(int r = 0; r < rows; r++) {
            dfs(r, cols - 1, heights, atlantic);
        }

        for(int c = 0; c < cols; c++) {
            dfs(rows - 1, c, heights, atlantic);
        }

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(pacific[r][c] == true && atlantic[r][c] == true) {
                    answer.push_back({r, c});
                }
            }
        }

        return answer;
        
    }
};