class Solution {
public:
  //leetcode 547
    void dfs(vector<vector<int>>&M,vector<vector<int>>& vis,int r,int c){
        if(r<0 || r> M.size() || c<0 || c> M.size()) return ;
        vis[r][c]=1;
        vis[c][r]=1;
        for(int i=0;i<M[0].size();i++){
            if(!vis[c][i] && M[c][i] == 1) dfs(M,vis,c,i);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && M[i][j] == 1) {
                    dfs(M,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
