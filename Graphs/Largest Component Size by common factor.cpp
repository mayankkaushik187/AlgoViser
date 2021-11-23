class disjoint_set {
    private:
        vector<int>parent, rank, size;
    public:
        disjoint_set(vector<int>& arr, int n) {
            parent.resize(n, -1), rank.resize(n), size.resize(n);
            for(int& a : arr) {
                size[a] = 1;
            }
        }
    
        int find(int i) {
            return parent[i] < 0 ? i : parent[i] = find(parent[i]);
        }
    
        bool Union(int i, int j) {
            int pi = find(i), pj = find(j);
            if(pi != pj) {
                if(rank[pi] < rank[pj]) {
                    parent[pi] = pj, size[pj] += size[pi], size[pi] = 0;
                }
                else parent[pj] = pi, size[pi] += size[pj], size[pj] = 0;
                
                rank[pi] += rank[pi] == rank[pj];
                
                return true;
            }
            
            return false;
        }
    
        int largestComponentSize() {
            return *max_element(begin(size), end(size));
        }
};
class Solution {
public:
    int largestComponentSize(vector<int>& arr) {
        int n = arr.size(), mx = *max_element(begin(arr), end(arr));
        disjoint_set d(arr, mx + 1);
        
        for(auto& a : arr) {
            for(int k = 2; k*k <= a; k++) {
                
                if(a % k == 0) {
                    d.Union(a, a/k);
                    d.Union(a, k);
                    
                }
            }
        }
        
        return d.largestComponentSize();
    }
};
