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
------------------------------------------------------------------------------------
int helper(vector<int>&arr, int index, int k, int n) {/*O(n*k) time complexity and O(n) aux space, no call stack overhead in this bottom up approach*/
 
	dp[0] = 0;
	for (int i = 1 ; i < n ; i++) {
		int ans = INT_MAX;
		for (int j = 1 ; j <= k ; j++) {
			if (i - j >= 0) {
				ans = min(ans, dp[i - j] + abs(arr[i - j] - arr[i]));
			}
		}
		dp[i] = ans;
	}
	return dp[n - 1];
}
------------------------------------------------------------------------------------
const int N = 1e5 + 5;
int dp[N];
int helper(vector<int>&arr, int index, int k, int n) {/*O(N*k) time complexity O(n) aux space as k options are being explored on each index */
	if (index >= n - 1)return 0;
	if (dp[index] != 0)return dp[index];
	int ans = INT_MAX;
	for (int i = 1 ; i <= k ; i++) {
		if (index + i < n)
			ans = min(ans, helper(arr, index + i, k , n) + abs(arr[index + i] - arr[index]));
	}
 
	return dp[index] = ans;
}
 
void solve() {
	memset(dp, 0, sizeof dp);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int index = 0;
	cout << helper(arr, index, k, n) << nline;
}
------------------------------------------------------------------------------------
int helper(vector<int>&arr, int index, int k, int n) {/*O(k^n) time complexity as we have k options for n indexes*/
	if (index >= n - 1)return 0;

	int ans = INT_MAX;
	for (int i = 1 ; i <= k ; i++) {
		if (index + i < n)
			ans = min(ans, helper(arr, index + i, k , n) + abs(arr[index + i] - arr[index]));
	}

	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int index = 0;
	cout << helper(arr, index, k, n) << nline;
}
------------------------------------------------------------------------------------

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
