#include<bits/stdc++.h>

using namespace std;

// sum
struct segmentTree {
	vector<int> st;

	segmentTree(int n) {
		st.resize(4 * n, 0);
	}

	void build(int start, int end, int node) {
		if (start == end) {
			return;
		}

		int mid = (start + end) / 2;
		// left build
		build(start, mid, 2 * node + 1);
		// right subtree
		build(mid + 1, end, 2 * node + 2);

		// coming back after building left subtree
		// and right subtree
		st[node] = (st[2 * node + 1] + st[2 * node + 2]);
	}

	void update(int start, int end,
	            int index, int value, int node) {
		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			// left update
			update(start, mid, index, value, 2 * node + 1);
		}
		else {
			// right update
			update(mid + 1, end, index, value, 2 * node + 2);
		}
		// while coming back update the current node
		st[node] = (st[2 * node + 1] + st[2 * node + 2]);
	}

	int query(int start, int end, int left, int right, int node) {
		// no overlap
		if (right < start || left > end) {
			return 0;
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

		return (leftAns + rightAns);
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	pair<int, int> b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = {a[i], i};
	}

	segmentTree St(n);

	sort(b, b + n);

	int inv_cnt = 0;

	for (int i = 0; i < n; i++) {
		int val = b[i].first;
		int index = b[i].second;


		// cout << val << " " << index << '\n';
		inv_cnt += St.query(0, n - 1, index + 1, n - 1, 0);

		St.update(0, n - 1, index, 1, 0);
	}

	cout << inv_cnt;

	return 0;
}