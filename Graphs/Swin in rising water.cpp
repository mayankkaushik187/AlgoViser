class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int ans = max(grid[0][0],grid[n - 1][n - 1]);
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        int dirs[5] = {-1,0,1,0,-1};
        pq.push({ans,0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ans = max(ans,curr[0]);
            for(int i = 0 ; i < 4 ; i++){
                int nx = curr[1] + dirs[i];
                int ny = curr[2] + dirs[i + 1];
                if(nx < n and ny < n and nx >= 0 and ny >= 0 and !visited[nx][ny]){
                    if(nx == n - 1 and ny == n - 1)return ans;
                    pq.push({grid[nx][ny],nx,ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0], high = n * n - 1;
        int ans = 0;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(valid(mid,grid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
public:
    int dirs[5] = {-1,0,1,0,-1};
    bool valid(int allow,vector<vector<int>>&grid){
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        return dfs(grid,allow,0,0,n,vis);
    }
    bool dfs(vector<vector<int>>&grid,int allow,int i,int j,int n,vector<vector<int>>&visited){
        visited[i][j] = 1;
        for(int id = 0 ; id < 4 ; id++){
            int nx = dirs[id] + i,ny = dirs[id + 1] + j;
            if(nx < 0 or nx >= n or ny < 0 or ny >= n or visited[nx][ny] or grid[nx][ny] > allow){
                continue;
            }
            if(nx == n - 1 and ny == n - 1)return true;
            if(dfs(grid,allow,nx,ny,n,visited))return true;
        }
        
        return false;
    }
};
