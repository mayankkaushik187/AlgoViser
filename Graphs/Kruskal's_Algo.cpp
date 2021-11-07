#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define ll long long
#define lli long long int

class DSU{
	int *parent;
	int *rank;
public:
	DSU(int n){
		parent = new int[n];
		rank = new int[n];
		for(int i = 0 ; i < n ; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	~DSU(){
		delete [] parent;
		delete [] rank;
	}
	int findSet(int x){
		if(parent[x] == -1)return x;

		return parent[x] = findSet(parent[x]);
	}
	void unite(int x,int y){
		int set1 = findSet(x);
		int set2 = findSet(y);
		if(set1 != set2){
			if(rank[set2] > rank[set1]){
				parent[set1] = set2;
				rank[set2] += rank[set1];
			}else{
				parent[set2] = set1;
				rank[set1] += rank[set2];
			}
		}
	}
};
class Graph{
	int V;
	vector<vector<int>> adj;
public:
	Graph(int V){
		this->V = V;
	}
	void addEdge(int x,int y,int w){
		adj.push_back({w,x,y});
	}

	int kruks_mst(){
		sort(adj.begin(),adj.end());
		//init a DSU 
		DSU s(V);
		int ans = 0;
		for(auto edge : adj){
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if(s.findSet(x)!=s.findSet(y)){
				s.unite(x,y);
				ans += w;
			}
		}
		return ans;
	}
};
int main(){
	Graph g(9);

	g.addEdge(2,5,1);
	g.addEdge(4,5,3);
	g.addEdge(4,2,3);
	g.addEdge(3,7,5);
	g.addEdge(5,7,6);
	g.addEdge(1,2,9);
	g.addEdge(1,3,8);
	g.addEdge(4,3,7);
	g.addEdge(3,6,8);
	g.addEdge(6,8,2);
	g.addEdge(3,5,10);
	g.addEdge(6,7,9);
	g.addEdge(8,7,11);
	g.addEdge(1,0,10);
	g.addEdge(0,2,12);

	cout<<g.kruks_mst()<<nline;//ans = 43
	return 0;	
}
