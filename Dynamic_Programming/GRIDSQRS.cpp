
#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
#define int long long int
#define all(x) x.begin(),x.end()
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())

#ifdef bihnehminduh
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i * i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<bool> isprime(int n) { vector<bool> sieve(n + 1, true); for (int i = 2 ; i * i <= n ; i++) { if (sieve[i]) { for (int j = 2 * i ; j <= n ; j += i) { sieve[j] = false; } } } return sieve; }
/*--------------------------------------------------------------------------------------------------------------------------*/
class Trip {
public:
	int left = 0;
	int upar = 0;
	int val = 0;
};

void solve() {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0 ; i < n ; i++) {
		string x;
		cin >> x;
		arr[i] = x;
	}
	int ans = 0;
	vector<vector<Trip>> dp(n, vector<Trip>(n));
	if (arr[0][0] == '1') {
		ans++;
		dp[0][0].val = dp[0][0].left = dp[0][0].upar = 1;
	} else {
		dp[0][0].val = dp[0][0].left = dp[0][0].upar = 0;
	}
	for (int i = 1; i < n ; i++) {
		if (arr[i][0] == '1') {
			ans++;
			dp[i][0].val = 1;
			dp[i][0].upar = dp[i - 1][0].upar + 1;
			dp[i][0].left = 1;
		} else {
			dp[i][0].upar = 0;
			dp[i][0].left = 0;
			dp[i][0].val = 0;
		}
	}
	for (int j = 1; j < n ; j++) {
		if (arr[0][j] == '1') {
			ans++;
			dp[0][j].val = 1;
			dp[0][j].left = dp[0][j - 1].left + 1;
			dp[0][j].upar = 1;
		} else {
			dp[0][j].upar = 0;
			dp[0][j].left = 0;
			dp[0][j].val = 0;
		}
	}

	for (int i = 1; i < n ; i++) {
		for (int j = 1; j < n ; j++) {
			int temp = 0;
			if (arr[i][j] == '1') {
				ans++;
				temp++;
				int x = j - 1;
				int y = i - 1;
				while (x >= 0 and y >= 0 and arr[i][x] == '1' and arr[y][j] == '1') {
					if (min(dp[i][x].upar , dp[y][j].left) >= j - x + 1) {
						ans++;
						temp++;
					}
					x--; y--;
				}

				dp[i][j].left = dp[i][j - 1].left + 1;
				dp[i][j].upar = dp[i - 1][j].upar + 1;
				dp[i][j].val = temp;
			}
		}
	}

	cout << ans << nline;



// 	vector<vector<pair<int, pair<int, int>>>> dp(n, vector<pair<int, pair<int, int>>>(n, {0, {0, 0}}));
// 	dp[0][0].ff = arr[0][0] == '1' ? 1 : 0;
// 	if (dp[0][0].ff) {
// 		ans++;
// 		dp[0][0].ss.ff = dp[0][0].ss.ss = 1;
// 	}
// 	for (int i = 1; i < n ; i++) {
// 		if (arr[i][0] == '1') {
// 			ans++;
// 			dp[i][0].ff = 1;
// 			dp[i][0].ss.ff = dp[i - 1][0].ss.ff + 1;
// 			dp[i][0].ss.ss = 1;
// 		}
// 	}
// 	for (int j = 1; j < n ; j++) {
// 		if (arr[0][j] == '1') {
// 			ans++;
// 			dp[0][j].ff = 1;
// 			dp[0][j].ss.ff = 1;
// 			dp[0][j].ss.ss = dp[0][j - 1].ss.ss + 1;
// 		}
// 	}

// 	for (int i = 1 ; i < n ; i++) {
// 		for (int j = 1 ; j < n ; j++) {
// 			if (arr[i][j] == '1') {
// 				ans++;
// 				dp[i][i].ff = 1;
// 				int left = j - 1;
// 				int upar = i - 1;
// 				while (left >= 0 and upar >= 0 and arr[i][left] == '1' and arr[upar][j] == '1') {
// 					if (min(dp[i][left].ss.ff, dp[upar][j].ss.ss) >= 2) {
// 						ans++;
// 					}
// 				}
// 				dp[i][j].ss.ff = dp[i - 1][j].ss.ff + 1;
// 				dp[i][j].ss.ss = dp[i][j - 1].ss.ss + 1;
// 			}
// 		}
// 	}=
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r" , stdin);
	freopen("output1.txt" , "w" , stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
