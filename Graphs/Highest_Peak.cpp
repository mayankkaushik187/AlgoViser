//MULTISOURCE BFS BASICS
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
class Solution {
public:
  //leetcode 1765
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> heights(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (isWater[i][j]) {
                    q.push({i, j});
                    heights[i][j] = 0;
                }
            }
        }
        //bfs
        int dirs[5] = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            auto x = q.front().ff;
            auto y = q.front().ss;
            q.pop();
            for (int i = 0 ; i < 4 ; i++) {
                int xx = x + dirs[i];
                int yy = y + dirs[i + 1];
                if (xx >= 0 and yy >= 0 and yy < m and xx < n and heights[xx][yy] == INT_MAX) {
                    q.push({xx, yy});
                    heights[xx][yy] = heights[x][y] + 1;
                }
            }
        }

        return heights;
    }

};
