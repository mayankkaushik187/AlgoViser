class Solution {
public:
//leetcode 934
    int dirs[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&visited, int col, int n, int m) {
        visited[i][j] = true;
        grid[i][j] = col;
        for (int k  = 0 ; k < 4 ; k++) {
            int xx = i + dirs[k];
            int yy = j + dirs[k + 1];

            if (xx >= 0 and yy >= 0 and xx < n and yy < m and grid[xx][yy] == 1 and visited[xx][yy] == false) {
                dfs(grid, xx, yy, visited, col, n, m);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int total_comp = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] and !visited[i][j]) {
                    total_comp++;
                    dfs(grid, i, j, visited, total_comp, n, m);
                }
            }
        }
        queue<pair<int, int>> q;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dirs[5] = {0, 1, 0, -1, 0};
        //bfs
        int ans = 0;
        while (!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            for (int i = 0 ; i < 4 ; i++) {
                int xx = x + dirs[i];
                int yy = y + dirs[i + 1];
                if (xx >= 0 and yy >= 0 and xx < n and yy < m and dist[xx][yy] == INT_MAX) {
                    q.push({xx, yy});
                    dist[xx][yy] = dist[x][y] + 1;
                }
            }
        }
        ans = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (grid[i][j] == 2) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return ans - 1;
    }
};
