class Solution {
public:
    bool helper(vector<vector<char>>&grid,int i,int j,string word,int n,int m,vector<vector<bool>>&vis){
        if(word.size() == 0){
            return true;
        }
        vis[i][j] = true;
        int dirs[5] = {1,0,-1,0,1};
        for(int ind = 0 ; ind < 4 ; ind++){
            int x = dirs[ind] + i;
            int y = dirs[ind+1] + j;
            if(x < 0 or y < 0 or x >= n or y >= m or grid[x][y] != word[0] or vis[x][y])continue;
            if(helper(grid,x,y,word.substr(1),n,m,vis))return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(helper(board,i,j,word.substr(1),n,m,vis))return true;
                }
            }
        }
        return false;
    }
};
