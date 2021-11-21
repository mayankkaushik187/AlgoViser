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
