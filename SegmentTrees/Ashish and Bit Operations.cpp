#include<bits/stdc++.h>
using namespace std;

struct sgmntree {
	int n;
	vector<int> st;
	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, vector<int> &arr, int operation) {
		//base case
		if (start == ending) {
			st[node] = arr[start];
			return;
		}
		//Find the mid
		int mid = start + (ending - start) / 2;
		//left subtree
		build(start, mid, 2 * node + 1, arr, operation - 1);

		//right subtree
		build(mid + 1, ending, 2 * node + 2, arr, operation - 1);
		//your work
		if (operation & 1) {
			st[node] = st[2 * node + 1] | st[2 * node + 2];
		} else {
			st[node] = st[2 * node + 1] ^ st[node * 2 + 2];
		}
	}
	void build(vector<int> &arr, int operation) {
		build(0, n - 1, 0, arr, operation);
	}
	//returns int because summation query
	int query(int start, int ending, int givenLeft, int givenRight, int node) {
		//case for no overlapping
		//here start and ending are the node indexes of our segment tree and givenL_R's the range of the curr query
		if (start > givenRight or ending < givenLeft) {
			return INT_MAX;
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

		return min(q1, q2);
	}


	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int start, int ending, int node, int index, int value, int operation) {
		//base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = start + (ending - start) / 2;
		if (index <= mid) {
			update(start, mid, node * 2 + 1, index, value, operation - 1);
		} else {
			update(mid + 1 , ending, node * 2 + 2, index, value, operation - 1);
		}

		if (operation & 1) {
			st[node] = st[2 * node + 1] | st[2 * node + 2];
		} else {
			st[node] = st[2 * node + 1] ^ st[2 * node + 2];
		}
	}
	void update(int index, int value, int operation) {
		update(0, n - 1, 0, index, value, operation);
	}

};
vector<int> solve(int n, vector<int> arr, vector<vector<int>> queries) {
	vector<int> res;
	sgmntree tree;
	int size = 1 << n;
	tree.init(size);
	tree.build(arr, n);
	for (int i = 0 ; i < int(queries.size()) ; i++) {
		int index = queries[i][0];
		int val = queries[i][1];
		tree.update(--index, val, n);
		res.push_back(tree.st[0]);
	}
	return res;
}
