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
---------------------------------------------------------------------------------
const int n = 1e5 + 5;
int dp[n];
int helper(vector<int>&arr, int N) {/*O(n) time complexity same and O(n) aux space 
  but we cut on the overhead due to stack calls in this bottom-up approach*/
 
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
 
	for (int i = 2 ; i < N ; i++) {
		dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
	}
 
	return dp[N - 1];
 
}
---------------------------------------------------------------------------------
const int n = 1e5 + 5;
int dp[n];
int helper(vector<int>&arr, int index, int N) {
 
	if (index >= N - 1) {
		return 0;
	}
	if (dp[index] != -1)return dp[index];
	int ans = INT_MAX;
	if (index + 2 < N) {
		int op1 = helper(arr, index + 2, N) + abs(arr[index + 2] - arr[index]);
		ans = min(ans, op1);
	}
	if (index + 1 < N) {
		int op2 = helper(arr, index + 1, N) + abs(arr[index + 1] - arr[index]);
		ans = min(ans, op2);
	}
 
	return dp[index] = ans;
 
}
 
void solve() {/*memoized solution (time complexity O(n) and O(n) axiliary space 
 as whenever we reach any index we will be storing its answer in out dp[] and 
 next time whenever a call is made to that index we will already have its 
 value so computation cost will be incurred */)
	int N;
	cin >> N;
	memset(dp, -1, sizeof dp);
 
	vector<int> arr(N);
	for (int i = 0 ; i < N ; i++) {
		cin >> arr[i];
	}
	cout << helper(arr, 0, N) << nline;
}
---------------------------------------------------------------------------------
int helper(vector<int>&arr, int index, int N) {
	if (index >= N - 1) {
		return 0;
	}

	int ans = INT_MAX;
	if (index + 2 < N) {
		int op1 = helper(arr, index + 2, N) + abs(arr[index + 2] - arr[index]);
		ans = min(ans, op1);
	}
	if (index + 1 < N) {
		int op2 = helper(arr, index + 1, N) + abs(arr[index + 1] - arr[index]);
		ans = min(ans, op2);
	}


	return ans;


}

void solve() {//recursion based approach (time complexity O(2^n) since we have 2 options on each index and there are n indexes)
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0 ; i < N ; i++) {
		cin >> arr[i];
	}

	cout << helper(arr, 0, N) << nline;
}
----------------------------------------------------------------------------------
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
