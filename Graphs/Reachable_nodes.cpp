//leetcode 882

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int,unordered_map<int,int>> graph;
        for(auto edge : edges)graph[edge[0]][edge[1]] = graph[edge[1]][edge[0]] = edge[2];//undir
        priority_queue<pair<int,int>> pq;
        pq.push({maxMoves,0});
        unordered_map<int,int> seen;
        while(!pq.empty()){
            int moves = pq.top().first, i = pq.top().second;
            pq.pop();
            if(!seen[i]){
                seen[i] = moves;
                for(auto j : graph[i]){
                    int moves2 = moves - (j.second + 1), nextNode = j.first;
                    if(!seen.count(nextNode) and moves2 >= 0){
                        pq.push({moves2,nextNode});
                    }
                }
            }
        }
        int ans = seen.size();
        for(auto edge : edges){
            int a = seen.find(edge[0]) == seen.end() ? 0 : seen[edge[0]];
            int b = seen.find(edge[1]) == seen.end() ? 0 : seen[edge[1]];
            ans += min(a + b,edge[2]);
        }
        return ans;
    }
};
