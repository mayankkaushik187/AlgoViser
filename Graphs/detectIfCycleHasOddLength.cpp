#include<bits/stdc++.h>

using namespace std;

bool solve(vector < vector < int >> graph) {
  int n = graph.size();
  vector < int > color(n, 0);
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      queue < int > q;
      color[i] = 1;
      q.push(i);
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto x: graph[f]) {
          if (color[x] == 0) {
            color[x] = 3 - color[f];
            q.push(x);
          } else {
            if (color[x] == color[f]) {
              return true;
            }
          }
        }
      }
    }
  }

  return false;
}
