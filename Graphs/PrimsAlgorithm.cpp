#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
class Graph{
	int V;
	vector<pair<int,int>> *adj;
	Graph(int V){
		this->V = V;
		adj = new vector<pair<int,int>>[V];
	}
	void addEdge(int x,int y,int w){
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	int prims_mst(){
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

		vector<bool> visited(V,false);
		pq.push({0,0});//weight and source
		visited[0] = true;
		int ans = 0;
		while(!pq.empty()){
			auto curr = pq.top();
			pq.pop();
			int weight = curr.first;
			int toNode = curr.second;
			if(visited[toNode])continue;
			ans += weight;
			visited[toNode] = true;
			for(auto edge : adj[toNode]){
				if(!visited[edge.first]){
					pq.push({edge.second,edge.first});
				}
			}
		}
		return ans;
	}
};
