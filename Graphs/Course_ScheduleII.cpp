class Solution {
private:
    void fillTheList(vector<int> adj[],int numCourses,vector<vector<int>>&prerequisites,vector<int>&indegree){
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
    }
    void initTheQueue(queue<int>& Q,vector<int>&indegree){
        for(int node = 0 ; node < indegree.size() ; node++){
            if(indegree[node] == 0){
                Q.push(node);
            }
        }
    }
    
    void bfs(vector<int>&result,queue<int>& Q, vector<int>&indegree,vector<int> adj[],int &numCourses){
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            result.push_back(front);
            numCourses--;
            for(auto &nbr : adj[front]){
                if(--indegree[nbr] == 0){
                    Q.push(nbr);
                }
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        queue<int> Q;
        vector<int> result;
        
        fillTheList(adj,numCourses,prerequisites,indegree);
        
        initTheQueue(Q,indegree);
        
        bfs(result,Q,indegree,adj,numCourses);
        
        if(numCourses == 0)return result;
        
        return {};
    }
};
