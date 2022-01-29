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
#define mod 1e9 + 7
#define INF 1e18L
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define ss second
using namespace std;
----------------------------------------------------------------
int sum;
int helper(vector<int>&weight, vector<int>&value, int remainVal, int W) {//O(N*sumOfValues) time and O(N * sumOfValues) space
	int n = weight.size();
	vector<vector<int>> dp(n, vector<int>(remainVal + 1, INT_MAX));
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j <= remainVal ; j++) {
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = 0;
	dp[0][value[0]] = weight[0];
	for (int i = 1 ; i < n ; i++) {
		dp[i][0] = 0;
		for (int j = 1 ; j <= remainVal; j++) {
			if (j >= value[i])
			{
				dp[i][j] = min(dp[i][j], dp[i - 1][j - value[i]] + weight[i]);
			}
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = remainVal ; i >= 0 ; i--) {
		if (dp[n - 1][i] <= W) {
			return i;
		}
	}
	return -1;
}


void solve() {
	// memset(dp, INF, sizeof dp);
	int n, W;
	cin >> n >> W;
	vector<int> weight(n), value(n);
	sum = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> weight[i] >> value[i];
		sum += value[i];
	}
	cout << helper(weight, value, sum, W) << nline;
}
----------------------------------------------------------------
int ans = INT_MIN;
int sum = 0;
int helper(vector<int>&weight, vector<int>&value, int index, int remainVal, vector<vector<int>>&dp) {
	//O(N*sumOfValues) time and O(N * sumOfValues) space
	if (index == value.size()) {
		return remainVal == 0 ? 0 : INT_MAX;
	}
	if (dp[index][remainVal] != -1)return dp[index][remainVal];
	int val = helper(weight, value, index + 1, remainVal, dp);
	if (value[index] <= remainVal) {
		val = min(val, helper(weight, value, index + 1, remainVal - value[index], dp) + weight[index]);
	}

	return dp[index][remainVal] = val;
}


void solve() {
	// memset(dp, INF, sizeof dp);
	int n, W;
	cin >> n >> W;
	vector<int> weight(n), value(n);
	sum = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> weight[i] >> value[i];
		sum += value[i];
	}
	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	for (int i = 0 ; i <= sum ; i++) {
		if (helper(weight, value, 0, i, dp) <= W) {
			ans = max(ans, i);
		}
	}
	cout << ans << nline;
}
----------------------------------------------------------------
int ans = INT_MIN;
int helper(vector<int>&weight, vector<int>&value, int index, int remainVal) {
	//O(2 ^ n) time
	if (index == weight.size()) {
		return remainVal == 0 ? 0 : INT_MAX;
	}
	int val = INT_MAX;
	if (value[index] <= remainVal) {
		val = min(val, helper(weight, value, index + 1, remainVal - value[index]) + weight[index]);
	}

	val = min(val, helper(weight, value, index + 1, remainVal));

	return val;

}


void solve() {
	int n, W;
	cin >> n >> W;
	int sum = 0;
	vector<int> weight(n), value(n);
	for (int i = 0 ; i < n ; i++) {
		cin >> weight[i] >> value[i];
		sum += value[i];
	}

	for (int i = 0 ; i <= sum ; i++) {
		if (helper(weight, value, 0, i) <= W) {
			ans = max(ans, i);
		}
	}
	cout << ans << nline;
}
----------------------------------------------------------------
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
