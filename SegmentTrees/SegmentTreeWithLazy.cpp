#include<bits/stdc++.h>
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
#define all(x) (x).begin(), (x).end()

#ifdef bihnehminduh
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
#define int long long int
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
struct sgmntree {
	int n;
	vector<int>st, lazy;
	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}
	//build will stay the same as the previous segment treee

	void build(int start, int ending, int node, vector<int>&arr) {
		if (start == ending) {
			st[node] = arr[start];
			return;
		}
		int mid = start + (ending - start) / 2;
		build(start, mid, 2 * node + 1, arr);
		build(mid + 1, ending, 2 * node + 2, arr);

		st[node] = st[2 * node + 1] + st[node * 2 + 2];
	}
	void build(vector<int>&arr) {
		build(0, n - 1, 0, arr);
	}
	int query(int start, int ending, int l, int r, int node) {
		//no overlap
		if (r < start or ending < l) {
			return 0;
		}
		//lazy propagation
		//first step clear the lazynodes
		if (lazy[node] != 0) {
			st[node] += lazy[node] * (ending - start + 1);
			if (start != ending) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			//make the parent node which propagated these values as 0
			lazy[node] = 0;
		}
		//full overlap
		if (l <= start and ending <= r) {
			return st[node];
		}
		//partial overlap
		int mid = start + (ending - start) / 2;
		int ans1 = query(start, mid, l, r, 2 * node + 1);
		int ans2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return ans1 + ans2;
	}
	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}
	void update(int start, int ending, int node, int l, int r, int value) {
		// non overlapping case
		if (start > r || ending < l) {
			return ;
		}

		// lazy propagation / clear the lazy update
		if (lazy[node] != 0) {
			// pending updates
			// update the segment tree node
			st[node] += lazy[node] * (ending - start + 1);
			if (start != ending) {
				// propagate the updated value
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			st[node] += value * (ending - start + 1);
			if (start != ending) {
				lazy[2 * node + 1] += value;
				lazy[2 * node + 2] += value;
			}
			return;
		}

		// partial case
		int mid = (start + ending) / 2;

		update(start, mid, 2 * node + 1, l, r, value);

		update(mid + 1, ending, 2 * node + 2, l, r, value);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;

	}
	void update(int l, int r, int value) {
		update(0, n - 1, 0, l, r, value);
	}
};

int32_t main() {
#ifdef bihnehminduh
	freopen("Error.txt", "w", stderr);
#endif
#ifdef bihnehminduh
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r", stdout);
#endif
	fastio();
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
	sgmntree tree;
	tree.init(8);
	tree.build(arr);
	cout << tree.query(0, 4) << " ";
	tree.update(0, 4, 2);
	cout << tree.query(0, 5) << " ";
	return 0;
}
