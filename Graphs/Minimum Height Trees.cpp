class Solution {
public:
//Leetcode 310
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)return {};
        if(n == 1)return {0};
        
        vector<int> res;
        vector<int> adj[n];
        vector<int> deg(n,0);
        
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            deg[edges[i][1]]++;
            deg[edges[i][0]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(deg[i] == 1)q.push(i),deg[i]--;
        }
        
        while(!q.empty()){
            int size = (int)q.size();
            res.clear();
            for(int i = 0 ; i < size ; i++){
                int curr = q.front();
                q.pop();
                
                res.push_back(curr);
                
                for(auto &nbr : adj[curr]){
                    deg[nbr]--;
                    if(deg[nbr] == 1){
                        q.push(nbr);
                    }
                }
            }
        }
        return res;
        
    }
};
