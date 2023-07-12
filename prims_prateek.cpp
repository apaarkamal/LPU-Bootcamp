#include<bits/stdc++.h>

using namespace std;

// O(nlogm)
int prims_mst(int source, vector<pair<int, int>> gr[], int n) {

	int mst = 0;
	vector<int> vis(n + 1, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>,
	               greater<pair<int, int>>> active_edges;

	// {w, y}
	active_edges.push({0, source});

	while (!active_edges.empty()) {

		pair<int, int> active_edge = active_edges.top();
		active_edges.pop();

		int cur = active_edge.second;
		int weight = active_edge.first;

		if (vis[cur]) continue;

		vis[cur] = 1;
		mst += weight;

		for (auto x : gr[cur]) {
			int y = x.first;
			int w = x.second;

			if (!vis[y]) {
				active_edges.push({w, y});
			}
		}
	}

	return mst;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> gr[n + 1];

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	cout << prims_mst(1, gr, n);

	return 0;
}