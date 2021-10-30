#include <bits/stdc++.h>
using namespace std;
//Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

int solve(vector<int> edges[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto x : edges[i])
        {
            for (auto y : edges[x])
            {
                if (y == i)
                {
                    continue;
                }
                for (auto k : edges[y])
                {
                    if (k == x)
                    {
                        continue;
                    }
                    if (k == i)
                    {
                        count++;
                    }
                }
            }
        }
    }

    return count / 6;
}

int main()
{
    // Write your code here
    int n, m;
    cin >> n >> m;
    vector<int> edges[n];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << solve(edges, n);
}
bool ans;
    void dfs(int node,vector&gt;&amp;v,vector&amp;vis){
        vis[node] = 1;
        
        for(auto x : v[node]){
            if(vis[x] != 0){
                dfs(x,v,vis);
            }else{
                if(vis[x] == 1){
                    ans = false;
                }
            }
        }
        vis[node] = 2;
    }
    
    bool canFinish(vector&gt; prerequisites,int numCourses) {
        vector vis(numCourses,0);
        ans = true;
        vector&gt; v(numCourses);
        for(int i = 0 ; i &lt; prerequisites.size() ; i++){
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int n = numCourses;
        for(int i = 0 ; i &lt; n ; i++){
            if(vis[i] == 0){
                dfs(i,v,vis);
            }
        }
        
        return ans;
    }