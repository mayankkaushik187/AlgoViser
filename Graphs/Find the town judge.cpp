class Solution {
public:
    int indeg[10001];
    
    int findJudge(int n, vector<vector<int>>& trust) {
        memset(indeg,0,sizeof indeg);
        for(int i = 0 ; i < trust.size(); ++i){
            indeg[trust[i][0]]--;
            indeg[trust[i][1]]++;
        }
        for(int i = 1;  i <= n ; i++){
            if(indeg[i] == n - 1){
                return i;
            }
        }
        return -1;
    }
};
