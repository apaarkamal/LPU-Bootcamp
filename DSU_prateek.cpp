#include<bits/stdc++.h>

using namespace std;

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

	DSU H(6);

	H.unite(5, 2);

	cout << H.isConnected(4, 2) << '\n';

	H.unite(4, 2);

	H.unite(5, 4);

	cout << "component -> " << H.total_component << '\n';

	cout << H.isConnected(4, 2) << '\n';

	H.unite(3, 2);

	H.unite(6, 2);

	H.unite(4, 6);

	cout << H.isConnected(5, 6) << '\n';








	return 0;
}