#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define ll long long
#define lli long long int

class DSU{
	vector<pair<int,int>> adj;
	int N;
public:
	DSU(int N){
		this->N = N;
	}
	void addEdge(int u,int v){
		adj.push_back({u,v});
	}
	int findSet(int x,vector<int>&parent){
		if(parent[x] == -1)return x;
		return parent[x] = findSet(parent[x],parent);//Path Compressed
	}
	void unionSet(int x,int y,vector<int>&parent,vector<int>&rank){
		int set1 = findSet(x,parent);
		int set2 = findSet(y,parent);

		if(set1!=set2){//union by rank
			if(rank[set1] > rank[set2]){
				parent[set2] = set1;
				rank[set1] += rank[set2];
			}else{
				parent[set1] = set2;
				rank[set2] += rank[set1];
			}
		}
	}

	bool containsCycle(){
		vector<int> parent(N,-1);
		vector<int> rank(N,1);//starting mein N ranks hongi with 1 node each so rank is 1 for each set
		for(auto edge : adj){
			int set1 = findSet(edge.first,parent);
			int set2 = findSet(edge.second,parent);
			if(set1 != set2){
				unionSet(set1,set2,parent,rank);
			}else{
				return true;
			}
		}
		return false;
	}
};

int main(){
#ifdef ONLINE_JUDGE
	freopen("input1.txt", "r" , stdin);
	freopen("output1.txt" ,"w" , stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	//cin>>n>>m;
	DSU g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	cout<<g.containsCycle()<<nline;
	return 0;
}
