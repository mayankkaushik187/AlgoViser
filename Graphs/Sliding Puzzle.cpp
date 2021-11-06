//Leetcode 773
class Solution {
public:
    string swap(string str, int i,int j){
        string res = str;
        char temp = str[j];
        res[j] = str[i];
        res[i] = temp;
        return res;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string end = "123450";
        string start = "";
        unordered_set<string> visited;
        int n = board.size(),m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                start += to_string(board[i][j]);
            }
        }
        vector<vector<int>> dirs = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                auto curr = q.front();
                q.pop();
                if(curr == end)return res;
                int zeroIndex = curr.find('0');
                for(auto dir : dirs[zeroIndex]){
                    string nextMove = swap(curr,zeroIndex,dir);
                    if(visited.find(nextMove)!=visited.end())continue;
                    visited.insert(nextMove);
                    q.push(nextMove);
                }
            }
            res++;
        }
        return -1;
    }
};
