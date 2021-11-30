void solve() {
	int n;
	cin >> n;
	if (n == 3 or n == 2) {
		cout << "NO SOLUTION" << nline;
		return;
	}
	for (int i = 2; i <= n ; i += 2) {
		cout << i << " ";
	}
	for (int i = 1 ; i <= n ; i += 2) {
		cout << i << " ";
	}

}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;//dadad
}
