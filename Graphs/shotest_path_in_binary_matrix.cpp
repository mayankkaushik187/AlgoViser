class Solution {
public:
    //leetcode 1091
    int ans = 0;
    int bfs(vector<vector<int>>&grid,int n){
        queue<pair<int,int>> q;
        q.push({0,0});
        int dx[8] = {1,0,-1,0,1,-1,1,-1};
        int dy[8] = {0,1,0,-1,1,1,-1,-1};
        grid[0][0] = 2;
        while(!q.empty()){
            int k = q.size();
            //ans = min(fr.second.second,ans);
            ans++;
            for(int x = 0 ; x < k ; x++){
                auto fr = q.front();
                q.pop();
                grid[fr.first][fr.second] = 2;
                if(fr.first == n - 1 and fr.second == n - 1)return ans;
                for(int i = 0 ; i < 8 ; i++){
                    int x = fr.first + dx[i];
                    int y = fr.second + dy[i];
                    if(x < 0 or y < 0 or x >= n or y >= n or grid[x][y]!=0)continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        return bfs(grid,n);
    }
};
