//Leetcode 743
class Graph{
	int V;
	vector<pair<int,int>> *adj;
public:
	Graph(int V){
		this->V = V;
		adj = new vector<pair<int,int>>[V];
	}
	void addEdge(int x,int y,int w,bool undir){
		adj[x].push_back({w,y});
		if(undir)
			adj[y].push_back({w,x});
	}

	int djikstras(int src){
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
        int maxm = 0;
		for(int i = 0 ; i < dist.size() ; i++){
			if(dist[i] == INT_MAX)return -1;
			maxm = max(maxm,dist[i]);
		}
		return maxm;
	}
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n);
        for(int i = 0 ; i < times.size() ; i++){
    	    g.addEdge(times[i][0] - 1,times[i][1] - 1,times[i][2],false);
        }
        return g.djikstras(k - 1);
    }
};
