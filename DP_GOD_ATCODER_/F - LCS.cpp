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

const int N = 3e3 + 5;

string s, t;
int memo[N][N];
int n, m;
string res;

int lcs(int i, int j) {
	if (i == n or j == m)return 0;
	if (memo[i][j] != -1)return memo[i][j];
	int ans;
	if (s[i] == t[j]) {
		ans = lcs(i + 1, j + 1) + 1;
	} else {
		ans = max(lcs(i + 1, j), lcs(i, j + 1));
	}
	return memo[i][j] = ans;
}
void trace_back(int i, int j) {
	if (i == n or j == m)return;
	if (s[i] == t[j]) {
		res += s[i], trace_back(i + 1, j + 1);
	} else {
		if (memo[i][j] == memo[i + 1][j]) {
			trace_back(i + 1, j);
		} else if (memo[i][j] == memo[i][j + 1]) {
			trace_back(i, j + 1);
		}
	}
}
void solve() {//O(n * m) time and O(N^2) space
	memset(memo, -1, sizeof memo);
	cin >> s >> t;
	n = s.size();
	m = t.size();
	int size = lcs(0, 0);
	res = "";
	trace_back(0, 0);
	cout << res << nline;
  //xoxo )
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
