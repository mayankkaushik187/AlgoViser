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
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<bool> isprime(int n) { vector<bool> sieve(n + 1, true); for (int i = 2 ; i * i <= n ; i++) { if (sieve[i]) { for (int j = 2 * i ; j <= n ; j += i) { sieve[j] = false; } } } return sieve; }
/*--------------------------------------------------------------------------------------------------------------------------*/
struct sgmntree {
	int n;
	vector<int> st;
	void init(int _n) {
		this->n = _n;
		st.clear();
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, vector<int> &arr) {
		//base case
		if (start == ending) {
			st[node] = arr[start];
			return;
		}
		//Find the mid
		int mid = start + (ending - start) / 2;
		//left subtree
		build(start, mid, 2 * node + 1, arr);

		//right subtree
		build(mid + 1, ending, 2 * node + 2, arr);
		//range summation
		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	}
	void build(vector<int> &arr) {
		build(0, n - 1, 0, arr);
	}
	//returns int because summation query
	int query(int start, int ending, int givenLeft, int givenRight, int node) {
		//case for no overlapping
		//here start and ending are the node indexes of our segment tree and givenL_R's the range of the curr query
		if (start > givenRight or ending < givenLeft) {
			return 0;
		}
		//full overlap
		// [givenLeft,..{start,...,ending}...givenRight]
		if (start >= givenLeft and ending <= givenRight) {
			return st[node];
		}
		//partial overlap
		int mid = start + (ending - start) / 2;
		int q1 = query(start, mid, givenLeft, givenRight, 2 * node + 1);
		int q2 = query(mid + 1, ending, givenLeft, givenRight, 2 * node + 2);

		return max(q1,q2);
	}


	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int start, int ending, int node, int index, int value) {
		//base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = start + (ending - start) / 2;
		if (index <= mid) {
			update(start, mid, node * 2 + 1, index, value);
		} else {
			update(mid + 1 , ending, node * 2 + 2, index, value);
		}

		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	}
	void update(int index, int value) {
		update(0, n - 1, 0, index, value);
	}

};
void solve() {
	int n;
	cin >> n;
	vector<int> h(n,0),b(n,0);
	sgmntree tree;
	vector<int> indices(n,0);
	for(int i = 0 ; i < n ; i++){
		cin >> h[i];
		h[i]--;
		indices[h[i]] = i;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> b[i];
	}
	vector<int> dp(n,0);
	tree.init(n);
	for(int height = 0 ; height < n ; height++){
		int index = indices[height];
		dp[index] = b[index] + tree.query(0,index - 1);
		tree.update(index,dp[index]);
	}
	cout << tree.query(0, n - 1);

}




int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	freopen("Error1.txt", "w", stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout << fixed << setprecision(18);
	int t = 1;
	// cin >> t;

	while (t--) {
		solve();
		// cout << '\n';
	}
	return 0;
}
//Bhai please thoda dhang se soch.
/*
Some things to remember when you're stuck:
1. Check for edge cases.
2. Stay Calm.
3. Don't be .stupid (search for silly mistakes).
4. Read problem again. Approach solution from different point of view.
5. In case of modulo, check for negative result (add MOD).

Some common C++ pit falls:
1. Don't use inbuilt ceil.
2. Never take inputs as double unless it is necessary.
3. Don't pass INT in accumulate.
*/
