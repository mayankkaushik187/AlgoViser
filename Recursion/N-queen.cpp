#include<bits/stdc++.h>
using namespace std;
  vector<vector<int>>res;
    bool isSafe(int row,int col,vector<vector<bool>>&board,int n){
        for(int i = 0 ; i < col ;i++){
            if(board[row][i])return false;
        }
        for(int i = row,j = col ; i >= 0 and j >= 0 ; i--,j--){
            if(board[i][j])return false;
        }
        for(int i = row, j = col ; i < n and j >= 0 ; i++ , j--){
            if(board[i][j])return false;
        }
        
        return true;
    }
    bool solveRec(int n,int col,vector<vector<bool>>& board){
        if(col == n){
            vector<int> temp;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j]){
                        temp.push_back(j+1);
                    }
                }
            }
            res.push_back(temp);
            return true;
        }
        bool res = false;
        for(int i = 0 ; i < n ; i++){
            if(isSafe(i,col,board,n)){
                board[i][col] = 1;
                res = solveRec(n,col+1,board) || res;
                board[i][col] = 0;
            }
        }
        return res;
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        if(n == 1){
            return {{1}};
        }
        vector<vector<bool>> board(n,vector<bool>(n,0));
        
        if(!solveRec(n,0,board))return {};
        sort(res.begin(),res.end());
        return res;
    }
