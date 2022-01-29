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
//debug
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
const int N = 305;
int arr[N];
int n;

long double memo[N][N][N];

long double dp(int a, int b, int c, int d) {
	if (b + c + d == 0)return 0;
	if(memo[b][c][d] != -1.00)return memo[b][c][d];
	long double ans = n;
	if (b)ans += b * dp(a + 1, b - 1, c, d);
	if (c)ans += c * dp(a, b + 1, c - 1, d);
	if (d)ans += d * dp(a, b, c + 1, d - 1);
	ans /= (long double)(n - a);
	return memo[b][c][d] = ans;
}

void solve() {
	cin >> n;
	int cnt[4] = {0};
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for(int i =0 ; i < N ; i++){
	    for(int j= 0 ; j < N ; j++){
	        for(int k = 0 ; k < N ; k++){
	            memo[i][j][k] = -1.00;
	        }
	    }
	}
	long double ans = dp(cnt[0], cnt[1], cnt[2], cnt[3]);
	cout << setprecision(10) << fixed;
	cout << ans << nline;
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
