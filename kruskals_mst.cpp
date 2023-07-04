#include<bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> par, sz;
	int component;

	void init(int n) {
		component = n;
		par.resize(n + 1);
		sz.resize(n, 1);
		iota(par.begin(), par.end(), 0);
	}

	int findSuperParent(int cur) {
		if (cur == par[cur]) return cur;
		return par[cur] = findSuperParent(par[cur]);
	}

	void unite(int x, int y) {
		int superx = findSuperParent(x);
		int supery = findSuperParent(y);

		if (superx != supery) {
			par[superx] = supery;

			sz[supery] += sz[superx];
			sz[superx] = 0;

			component--;
		}
		return;
	}

	bool isSameComponent(int x, int y) {
		return findSuperParent(x) == findSuperParent(y);
	}

	int totalComponents() {
		return component;
	}

};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({w, x, y});
	}

	DSU H;
	H.init(n);

	sort(edges.begin(), edges.end());

	int mst = 0;

	for (auto edge : edges) {
		int w = edge[0], x = edge[1], y = edge[2];
		// cout << w << " " << x << " " << y << '\n';
		if (!H.isSameComponent(x, y)) {
			mst += w;
			H.unite(x, y);
		}
	}

	cout << mst;


	return 0;
}