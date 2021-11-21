class Solution {
public:
//leetcode 207
    //0 ---> not visited, 1 ---> processing 2--->processed
    bool isCyclePresent(vector<int> adj[], int node, vector<int>&vis) {
        if (vis[node] == 1)return true;
        if (vis[node] == 0) {
            visited[node] = 1;
            for (auto&edge : adj[node]) { //every edge with node will be traversed
                if (isCyclePresent(adj, edge, vis))return true;
            }
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto&edges : prerequisites) {
            adj[edges[1]].push_back(edges[0]);
        }

        vector<int> vis(numCourses, false);

        for (int i = 0 ; i < numCourses ; i++) {
            if (vis[i] == 0) {
                if (isCyclePresent(adj, i, vis))return false;
            }
        }
        return true;
    }
};


//Topological Sort method
class Solution {
private:
    queue<int> getZeroInDegreeNode(vector<int>& indegree) {

        int n = indegree.size();
        queue<int> q;
        for (int i = 0; i < n ; i++) {
            if (indegree[i] == 0)q.push(i);
        }
        return q;
    }
    void bfs(queue<int>&q, vector<int>&indegree, int &numCourses, vector<int> adj[]) {
        //the idea is that we need to complete all the courses successfully so the
        //the number of time this while loop runs should be equal to the number courses
        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            numCourses--;
            for (auto &edges : adj[fr]) {
                if (--indegree[edges] == 0) {
                    q.push(edges);
                }
            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        vector<int> indegree(numCourses, 0);

        for (auto&edges : prerequisites) {
            indegree[edges[0]]++;
            adj[edges[1]].push_back(edges[0]);
        }

        queue<int> q = getZeroInDegreeNode(indegree);

        bfs(q, indegree, numCourses, adj);

        return numCourses == 0;
    }
};
