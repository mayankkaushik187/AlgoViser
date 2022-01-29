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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int N = 105;
const int K = 1e5 + 5;
int dp[K];
int arr[N];
int n, k;

bool helper(int turn, int index, int k) {
	for (int i = 0 ; i < n ; i++) {
		dp[arr[i]] = 1;
	}
	dp[0] = 0;
	for (int i = 1 ; i <= k ; i++) {
		if (dp[i] != -1)continue;
		int ans = 1;
		for (auto &x : arr) {
			if (i - x >= 0) {
				ans = ans & dp[i - x];
				if (!ans)break;
			}
		}
		if (ans) {
			dp[i] = 0;
		} else {
			dp[i] = 1;
		}
	}
	return dp[k];
}

void solve() {
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	cout << (helper(0, 0, k) ? "First" : "Second");
}

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
