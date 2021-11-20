class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int col_count[100001] = {0};
    void dfs(vector<vector<int>>&grid, int i, int j, int col, int n, vector<vector<bool>> &vis) {
        grid[i][j] = col;
        col_count[col]++;
        vis[i][j] = true;

        for (int x = 0 ; x < 4 ; x++) {
            int xx = i + dx[x];
            int yy = j + dy[x];

            if (xx < 0 or xx >= n or yy < 0 or yy >= n or vis[xx][yy] == true or grid[xx][yy] != 1) {
                continue;
            }
            dfs(grid, xx, yy, col, n, vis);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int comp_count = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1 and !vis[i][j]) {
                    comp_count++;
                    dfs(grid, i, j, comp_count, n, vis);
                }
            }
        }
        //cout << comp_count << nline;
        //largestIsland
        int largest = 0;
        for (int i = 1; i <= comp_count ; i++) {
            largest = max(largest, col_count[i]);
        }
        //cout << largest << nline;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 0) {
                    set<int> st;
                    int ans = 1;
                    for (int k = 0 ; k < 4 ; k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (xx < n and yy < n and xx >= 0 and yy >= 0) {
                            st.insert(grid[xx][yy]);
                        }
                    }
                    for (auto x : st) {
                        ans += col_count[x];
                    }
                    //ans += col_count[]
                    largest = max(ans, largest);
                }
            }
        }
        return largest;
    }
};
