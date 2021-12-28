// ▒▒▒▒▒▒▒▒▒▒▒▄▄▄▄░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒▒▒▒▒▒▄██████▒▒▒▒▒▄▄▄█▄▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒▒▒▒▄██▀░░▀██▄▒▒▒▒████████▄▒▒▒▒▒▒
// ▒▒▒▒▒▒███░░░░░░██▒▒▒▒▒▒█▀▀▀▀▀██▄▄▒▒▒
// ▒▒▒▒▒▄██▌░░░░░░░██▒▒▒▒▐▌▒▒▒▒▒▒▒▒▀█▄▒
// ▒▒▒▒▒███░░▐█░█▌░██▒▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▀▌
// ▒▒▒▒████░▐█▌░▐█▌██▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▐████░▐░░░░░▌██▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒████░░░▄█░░░██▒▒▐█▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒████░░░██░░██▌▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒████▌░▐█░░███▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒▐████░░▌░███▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒▒▒████░░░███▒▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▒▒██████▌░████▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒▐████████████▒▒███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ▒█████████████▄████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ██████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ██████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// █████████████████▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// █████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// ████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
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
#define rep(x,a,b) for(int (x) = (a) ; (x) < (b) ; (x)++)
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
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i * i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<bool> isprime(int n) { vector<bool> sieve(n + 1, true); for (int i = 2 ; i * i <= n ; i++) { if (sieve[i]) { for (int j = 2 * i ; j <= n ; j += i) { sieve[j] = false; } } } return sieve; }
/*--------------------------------------------------------------------------------------------------------------------------*/
//Bhai please thoda dhang se soch.
/*
Some things to remember when you're stuck:
    1. Check for edge cases.
    2. Stay Calm.
    3. Don't be stupid (search for silly mistakes).
    4. Read problem again. Approach solution from different point of view.
    5. In case of modulo, check for negative result (add MOD).

Some common C++ pit falls:
    1. Don't use inbuilt ceil.
    2. Never take inputs as double unless it is necessary.
    3. Don't pass INT in accumulate.
*/
void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool ans = 1;
	vector<pair<int, int>> pre(n);
	pre[0].ff = a[0] == '1';
	pre[0].ss = a[0] == '0';
	for (int i = 1 ; i < n ; i++) {
		if (a[i] == '1') {
			pre[i].ff = pre[i - 1].ff + 1;
			pre[i].ss = pre[i - 1].ss;
		} else {
			pre[i].ss = pre[i - 1].ss + 1;
			pre[i].ff = pre[i - 1].ff;
		}
	}
	int flipper = 1;
	for (int i = n - 1; i >= 0 ; i--) {
		if (flipper) {
			if (a[i] == b[i])continue;
			else {
				if (pre[i].ff != pre[i].ss) {
					ans = false;
					break;
				} else {
					flipper ^= 1;
				}
			}
		} else {
			if (a[i] != b[i])continue;
			else {
				if (pre[i].ff != pre[i].ss) {
					ans = false;
					break;
				} else {
					flipper = !flipper;
				}
			}
		}
	}


	cout << (ans ? "YES" : "NO") << nline;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r" , stdin);
	freopen("output1.txt" , "w" , stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout << fixed << setprecision(18);
	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}
