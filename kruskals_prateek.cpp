#include<bits/stdc++.h>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

struct DSU {
	vector<int> par, sz;
	int total_component;

	// O(n)
	DSU(int n) {
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		total_component = n;
		// par[i]=i
		iota(par.begin(), par.end(), 0);
	}

	// O(1)
	int getSuper(int x) {
		if (x == par[x]) return x;
		return par[x] = getSuper(par[x]);
	}

	// O(1)
	void unite(int x, int y) {
		int super_x = getSuper(x);
		int super_y = getSuper(y);

		if (super_x != super_y) {
			par[super_x] = super_y;

			sz[super_y] += sz[super_x];
			sz[super_x] = 0;

			total_component--;
		}
	}

	// O(1)
	bool isSameComponent(int x, int y) {
		return getSuper(x) == getSuper(y);
	}

	// O(1)
	bool isConnected(int x, int y) {
		return isSameComponent(x, y);
	}

	int sizeOfConnectedComponent(int x) {
		// set size
		return sz[getSuper(x)];
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	// vector<pair<pair<int,int>, int>> edges;
	vector<vector<int>> edges;

	// x, y, w
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({w, x, y});
	}

	sort(edges.begin(), edges.end());

	DSU H(n);
	int mst = 0;

	for (auto v : edges) {
		// cout << v[0] << " " << v[1] << " " << v[2] << '\n';
		int w = v[0], x = v[1], y = v[2];

		if (!H.isConnected(x, y)) {
			cout << "edge -> " << x << " " << y << " " << w << '\n';
			mst += w;
			H.unite(x, y);
		}

	}

	cout << mst;




	return 0;
}