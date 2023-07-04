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

	int n;
	cin >> n;

	DSU H;
	H.init(n);

	H.unite(1, 2);

	cout << H.isSameComponent(3, 4) << '\n';

	H.unite(1, 6);

	cout << H.isSameComponent(6, 1) << '\n';

	H.unite(4, 3);

	H.unite(5, 1);

	cout << H.isSameComponent(6, 4) << '\n';

	H.unite(6, 4);

	cout << H.isSameComponent(3, 5) << '\n';

	return 0;
}