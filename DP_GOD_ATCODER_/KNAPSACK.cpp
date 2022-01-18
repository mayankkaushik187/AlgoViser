#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define nline "\n"
#define int long long int
#define all(x) x.begin(),x.end()
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

// const int N = 105;
// const int W = 1e5 + 5;
// int dp[N][W];
//----------------------------------------------------------------
int helper(vector<int>&weight,vector<int>&value,int n,int maxWeight) {/*O(n*w) time complexity*/
		vector<vector<int>> dp(n,vector<int>(maxWeight + 1,0));
    for(int i = 0 ; i < n ; i++){
    	dp[i][0] = 0;
    }
    for(int i = 0 ; i <= maxWeight ; i++){
    	if(weight[0] <= i){
    		dp[0][weight[0]] = value[0];
    	}
    }
    for(int i = 1; i < n ; i++){
    	for(int j = 1 ; j <= maxWeight ; j++){
    		if(j >= weight[i]){
    			dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
    		}
    		dp[i][j] = max(dp[i][j],dp[i - 1][j]);
    	}
    }
    int ans = INT_MIN;
    for(int i = 0 ; i <= maxWeight ; i++){
    	ans = max(ans,dp[n - 1][i]);
    }
    return ans;
    
}
//----------------------------------------------------------------
int helper(vector<int>&weight,vector<int>&value,int index,int n,int maxWeight) {/*O(n*w) time complexity*/
    if(index >= n or maxWeight <= 0)return 0;
    if(dp[index][maxWeight] != -1)return dp[index][maxWeight];
    int op1 = helper(weight,value,index + 1,n,maxWeight);

    int op2 = maxWeight >= weight[index] ? helper(weight,value,index + 1,n,maxWeight - weight[index]) + value[index] : 0;


    return max(op1,op2);
}
// ----------------------------------------------------------------
int helper(vector<int>&weight,vector<int>&value,int index,int n,int maxWeight) {/*O(2^n) time complexity*/
    if(index >= n or maxWeight <= 0)return 0;
    int op1 = helper(weight,value,index + 1,n,maxWeight);

    int op2 = maxWeight >= weight[index] ? helper(weight,value,index + 1,n,maxWeight - weight[index]) + value[index] : 0;


    return max(op1,op2);
}

void solve() {
  memset(dp, -1, sizeof dp);	
  int n,w;
  cin >> n >> w;
  vector<int> weight(n),value(n);
  for(int i = 0 ; i < n ; i++){
      cin >> weight[i] >> value[i];
  }
  // int index = 0;
  int maxWeight = w;
  cout << helper(weight,value,n,maxWeight);
}
// ----------------------------------------------------------------

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r" , stdin);
  freopen("output.txt" , "w" , stdout);
  freopen("Error1.txt", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  // cin.ignore(); must be there when using getline(cin, s)
  while (T--)
  {
    solve();
  }
  return 0;
}
