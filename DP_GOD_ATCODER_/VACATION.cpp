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
--------------------------------------------------------------------
vector<vector<int>> dp;
int helper(vector<vector<int>>&arr, int index, int n, int task) {/*O(n) time complexity it is pretty self explanatory just one loop doing n iterations and in each
iteration O(1) work is being done*/
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (int i = 1; i < n ; i++) {
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	int maxm = INT_MIN;
	for (int i = 0; i < 3 ; i++) {
		maxm = max(maxm, dp[n - 1][i]);
	}
	return maxm;
}
----------------------------------------------------------------
vector<vector<int>> dp;
int helper(vector<vector<int>>&arr, int index, int n, int task) {/*O(3*n) => O(n) as on each index we have 3 options 
and all those options when explored will require computation just once, i.e, the overall time complexity will get reduced
memoized solutions using dp[][]*/
	if (index >= n)return 0;
	if (dp[index][task] != 0)return dp[index][task];
	int ans = 0;
	int op1 = 0, op2 = 0, op3 = 0;
	if (task != 0) {
		op1 = helper(arr, index + 1, n, 0) + arr[index][0];
	}
	if (task != 1) {
		op2 = helper(arr, index + 1, n, 1) + arr[index][1];
	}
	if (task != 2) {
		op3 = helper(arr, index + 1, n, 2) + arr[index][2];
	}
 
	ans = max({ans, op1, op2, op3});
 
	return dp[index][task] = ans;
}
 
void solve() {
	// memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	dp.resize(n, vector<int>(4, 0));
	vector<vector<int>> arr(n, vector<int>(3, 0));
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			cin >> arr[i][j];
		}
	}
	int index = 0;
 
 
	cout << helper(arr, index, n, 3) << nline;
}
----------------------------------------------------------------
const int N = 1e5 + 5;
int dp[N];
int helper(vector<vector<int>>&arr, int index, int n, int task) {/*O(3^n) time complexity as on the first row we have 3 options to choose 
  from and on all the other indexes we have 2 options.*/
	if (index >= n)return 0;
	int ans = 0;
	int op1 = 0, op2 = 0, op3 = 0;
	if (task != 0) {
		op1 = helper(arr, index + 1, n, 0) + arr[index][0];
	}
	if (task != 1) {
		op2 = helper(arr, index + 1, n, 1) + arr[index][1];
	}
	if (task != 2) {
		op3 = helper(arr, index + 1, n, 2) + arr[index][2];
	}

	ans = max({ans, op1, op2, op3});

	return ans;
}

void solve() {
	// memset(dp, 0, sizeof dp);
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(3, 0));
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			cin >> arr[i][j];
		}
	}
	int index = 0;


	cout << helper(arr, index, n, -1) << nline;
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
