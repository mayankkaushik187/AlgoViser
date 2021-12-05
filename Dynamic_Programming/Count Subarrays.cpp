#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define int long long int
#define all(x) x.begin(),x.end()
#define pb push_back
vector<bool> sieve(int n){vector<bool> si(n + 1,true);si[0] = false;si[1] = false;for(int i = 2 ; i <= sqrt(n) ; i++){if(si[i]){for(int j = i*i ; j <= n ; j += i){si[j] = false;}}}return si;}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i =0 ; i < n ; i++){
		cin>>arr[i];
	}

	vector<int> dp(n,1);
	for(int i = 1; i < n ; i++){
		if(arr[i - 1] <= arr[i]){
			dp[i] = dp[i-1] + 1;
		}
	}
	int sum  = 0;
	for(int i : dp){
		sum += i;
	}
	cout<<sum<<nline;

} 

/*
2
4
1 4 2 3
1 1 1 1
1 2 

1
5
*/

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r" , stdin);
	freopen("output1.txt" ,"w" , stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
