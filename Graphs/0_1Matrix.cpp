//Leetcode 542
class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i < 0 or j < 0 or i >= m or j >= n)return false;
        return true;
    }
    void bfs(vector<vector<int>>&res,vector<vector<int>>&mat,queue<pair<int,int>>&q,int m,int n){
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            int x = fr.first;
            int y = fr.second;
            pair<int,int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dirs[i].first,ny = y + dirs[i].second;
                if(isValid(nx,ny,m,n) and res[nx][ny] == -1){
                    q.push({nx,ny});
                    res[nx][ny] = res[x][y] + 1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(m,vector<int>(n,-1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }
        bfs(res,mat,q,m,n);
        return res;
    }
};
