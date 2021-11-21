class Solution {
private:
    void fillTheList(vector<int> adj[], vector<int>&indegree, int n, vector<vector<int>>&prerequisites) {

        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
    }
    void pushNodeWithZeroIndegree(queue<int> &q, vector<int>&indegree, int n, vector<int>&result) {
        for (int i = 0 ; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
            }
        }
    }
    void bfs(vector<int>&temp, vector<int>adj[], queue<int>&q, vector<int>&indegree, int &n) {
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            n--;
            //temp.push_back(front);
            for (auto &edge : adj[front]) {
                if (--indegree[edge] == 0) {
                    q.push(edge);
                    temp.push_back(edge);
                }
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        int n = numCourses;
        vector<int> indegree(n, 0);

        vector<int> adj[numCourses];

        fillTheList(adj, indegree, n, prerequisites);

        queue<int> q;

        pushNodeWithZeroIndegree(q, indegree, n, result);

        bfs(result, adj, q, indegree, n);

        if(n == 0)return result;
        return {};
    }
};

