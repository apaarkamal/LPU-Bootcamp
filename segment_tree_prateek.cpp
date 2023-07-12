#include<bits/stdc++.h>

using namespace std;

// minimum
struct segmentTree {
	vector<int> st;

	segmentTree(int n) {
		st.resize(4 * n, INT_MAX);
	}

	void build(int a[], int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return;
		}

		int mid = (start + end) / 2;
		// left build
		build(a, start, mid, 2 * node + 1);
		// right subtree
		build(a, mid + 1, end, 2 * node + 2);

		// coming back after building left subtree
		// and right subtree
		st[node] = min(st[2 * node + 1], st[2 * node + 2]);
	}

	void update(int a[], int start, int end,
	            int index, int value, int node) {
		if (start == end) {
			a[index] = value;
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			// left update
			update(a, start, mid, index, value, 2 * node + 1);
		}
		else {
			// right update
			update(a, mid + 1, end, index, value, 2 * node + 2);
		}
		// while coming back update the current node
		st[node] = min(st[2 * node + 1], st[2 * node + 2]);
	}

	int query(int start, int end, int left, int right, int node) {
		// no overlap
		if (right < start || left > end) {
			return INT_MAX;
		}

		// complete overlap
		// segment lies inside the query range
		if (start >= left && end <= right) {
			return st[node];
		}

		// partial overlap
		// reverse complete overlap
		// query lies inside the segment
		int mid = (start + end) / 2;
		int leftAns = query(start, mid, left, right, 2 * node + 1);
		int rightAns = query(mid + 1, end, left, right, 2 * node + 2);

		return min(leftAns, rightAns);
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	segmentTree St(n);

	St.build(a, 0, n - 1, 0);

	St.update(a, 0, n - 1, 2, 0, 0);

	cout << St.query(0, n - 1, /*l*/ 3, /*r*/7, 0) << '\n';
	cout << St.query(0, n - 1, /*l*/ 0, /*r*/2, 0) << '\n';
	cout << St.query(0, n - 1, /*l*/ 3, /*r*/3, 0) << '\n';


	return 0;
}