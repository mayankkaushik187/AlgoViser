class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&graph,vector<string>&ma,string src,unordered_set<string>&vis){
        vis.insert(src);
        ma.push_back(src);
        for(auto& edge : graph[src]){
            if(vis.find(edge) == vis.end())
                dfs(graph,ma,edge,vis);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> graph;
        unordered_set<string> visited;
        
        for(int i = 0 ; i < accounts.size() ; i++){
            for(int j = 2 ; j < accounts[i].size() ; j++){
                graph[accounts[i][1]].push_back(accounts[i][j]);
                graph[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        vector<vector<string>> res;
        for(int i = 0 ; i < accounts.size() ; i++){
            string accountName = accounts[i][0];
            string sourceEmail = accounts[i][1];
            vector<string> mergeAccount;
            if(visited.find(sourceEmail) == visited.end()){
                mergeAccount.push_back(accountName);
                dfs(graph,mergeAccount,sourceEmail,visited);
                sort(mergeAccount.begin() + 1,mergeAccount.end());
            
                res.push_back(mergeAccount);
            }
            
                
        }
        return res;
    }
};
