#include<bits/stdc++.h>

using namespace std;

// PRIM'S MST
const int N = 1e5;
vector<pair<int, int>> gr[N];
int vis[N];

// O(m logn)
vector<int> dijkstra(int source) {

	vector<int> min_dis(N, -1);

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> Q;

	Q.push({0, source});

	while (!Q.empty()) {
		// minimum weight edge
		pair<int, int> cur = Q.top();
		Q.pop();

		int curnode = cur.second;
		// minimum weight path
		int weight_of_path = cur.first;

		if (vis[curnode]) continue;

		cout << curnode << " " << weight_of_path << '\n';

		vis[curnode] = 1;
		min_dis[curnode] = weight_of_path;

		for (auto x : gr[curnode]) {
			int y = x.first;
			int w = x.second;

			if (!vis[y]) {
				Q.push({min_dis[curnode] + w, y});
			}
		}
	}

	return min_dis;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	vector<int> min_dis = dijkstra(9);

	for (int i = 1; i <= n; i++) {
		cout << i << " -> " << min_dis[i] << '\n';
	}

	return 0;
}