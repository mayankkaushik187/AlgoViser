#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define ll long long
#define lli long long int

class Graph{
	int V;
	vector<pair<int,int>> *adj;
public:
	Graph(int V){
		this->V = V;
		adj = new vector<pair<int,int>>[V];
	}
	void addEdge(int x,int y,int w,bool undir = true){
		adj[x].push_back({w,y});
		if(undir)
			adj[y].push_back({w,x});
	}

	int djikstras(int src,int dest){
		//Data structures
		//set, dist arr
		vector<int> dist(V,INT_MAX);
		set<pair<int,int>> s;
		//insert the src to set
		dist[src] = 0;
		s.insert({0,src});
		while(!s.empty()){
			auto it = s.begin();
			int node = it->second;
			int distTillNow = it->first;
			s.erase(it);//pop
			for(auto nbr : adj[node]){
				int nbrNode = nbr.second;
				int currEdgeDist = nbr.first;
				if(currEdgeDist + distTillNow < dist[nbrNode]){
					auto f = s.find({dist[nbrNode],nbrNode});

					if(f!=s.end()){
						s.erase(f);
					}
					dist[nbrNode] = currEdgeDist + distTillNow;
					s.insert({dist[nbrNode],nbrNode});

				}
			}

		}
		return dist[dest];
	}
};
int main(){
// #ifdef ONLINE_JUDGE
// 	freopen("input1.txt", "r" , stdin);
// 	freopen("output1.txt" ,"w" , stdout);
// #endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout<<g.djikstras(0,4)<<nline;
	return 0;	
}
