#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define int long long int
#define all(x) x.begin(),x.end()
#define pb push_back
vector<bool> sieve(int n){vector<bool> si(n + 1,true);si[0] = false;si[1] = true;for(int i = 2 ; i <= sqrt(n) ; i++){if(si[i]){for(int j = 2*i ; j <= n ; j += i){si[j] = false;}}}return si;}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve(){
	string s;
	cin>>s;
	vector<int> dp(s.size(), 0);
	dp[0] = 0;
	int n = s.size();
	for(int i = 1 ; i < n ; i++){
		if(dp[i - 1] == 0 and s[i] != s[i-1]){
			dp[i] = dp[i-1] + 1;
		}
	}
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		count += dp[i];
	}
	cout<<count<<nline;

} 

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
