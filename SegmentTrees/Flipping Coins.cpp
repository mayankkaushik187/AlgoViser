#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void build (int ss, int se, int idx, vector <int> & tree){
    if (ss == se){
        tree[idx] = 0;
        return ;
    }
    
    if (ss < se){
        int mid = (ss + se) / 2 ;
        
        build (ss, mid, 2*idx + 1, tree) ;
        build (mid + 1, se, 2*idx + 2, tree) ;
        
        tree[idx] = tree [2*idx + 1] + tree[2*idx + 2] ; 
        return ;
    }
}

void update (int ss, int se, int i, int j, int idx, vector <int> &tree, vector <int> &lazy){
    
    if (lazy[idx] != 0){
        tree[idx] = (se - ss + 1) - tree[idx] ; 
        
        if (ss != se){
            lazy[2*idx + 1] = 1 ^ lazy[2*idx + 1] ;
            lazy[2*idx + 2] = 1 ^ lazy[2*idx + 2] ;
        }
        
        lazy[idx] = 0 ;
    }
    
    if (ss > se || j < ss || i > se)
    return ;
    
    if (ss >= i && se <= j){
        tree[idx] = (se - ss + 1) - tree[idx] ;
        
        if (ss != se){
            lazy[2*idx + 1] = 1 ^ lazy[2*idx + 1] ;
            lazy[2*idx + 2] = 1 ^ lazy[2*idx + 2] ;
        }
        return ;
    } 
    
    int mid = (ss + se) / 2;
    
    update (ss, mid, i, j, 2*idx + 1, tree, lazy) ;
    update (mid + 1, se, i, j, 2*idx + 2, tree, lazy) ;
    
    tree [idx] = tree [2*idx + 1] + tree[2*idx + 2] ;
}

int count (int ss, int se, int i, int j, int idx,  vector <int> &tree, vector <int> &lazy){
    if (lazy[idx] != 0){
        tree[idx] = (se - ss + 1) - tree[idx] ;
        
        if (ss != se){
            lazy [2*idx + 1] = 1 ^ lazy[2*idx + 1] ;
            lazy [2*idx + 2] = 1 ^ lazy[2*idx + 2] ;
        }
        
        lazy[idx] = 0 ;
    }
    
    if (ss > se || ss > j || se < i)
    return 0;
    
    if (ss >= i && se <= j)
    return tree[idx] ;
    
    int mid = (ss + se) / 2 ;
    
    return count (ss, mid, i, j, 2*idx + 1, tree, lazy) + count (mid + 1, se, i, j, 2*idx + 2, tree, lazy) ;
}

int main() {

	int n, q;
	cin >> n >> q;
		
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	
    vector <int> lazy (4*n + 9, 0) ;
    vector <int> tree (4*n + 9) ;
    
    build (0, n-1, 0, tree) ;
	
	for (int i = 0; i< q; i++){
	    
	    int p, a, b ;
	    cin >> p >> a >> b;
	    
	    if (p == 0)
	    update(0, n-1, a, b, 0, tree, lazy) ;
	     
	    else{
	        int res = count (0, n-1, a, b, 0, tree, lazy) ;
	        cout << res << '\n' ;
	    }
	}
	
	return 0;
}
