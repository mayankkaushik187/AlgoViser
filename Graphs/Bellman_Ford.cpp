#include <bits/stdc++.h>

using namespace std;
#define nline "\n"
#define ll long long
#define lli long long int

vector < int > bellman_ford(vector < vector < int >> & edges, int V, int src) {
    vector < int > dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto edge: edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX and dist[u] + w < dist[v]) {
            return {};
        }
    }
    return dist;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < vector < int >> edges(m, vector < int > (m, 0));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector < int > ans = bellman_ford(edges, n, 0);
    if (ans.size() == 0) cout << "Negative weight cycle found" << nline;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;

}
