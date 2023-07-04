#include<bits/stdc++.h>

using namespace std;

// PRIM'S MST
const int N = 1e5;
vector<pair<int, int>> gr[N];
int in_mst[N];

int prims_mst(int source) {

	int mst = 0;

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> Q;

	Q.push({0, source});

	while (!Q.empty()) {
		// minimum weight edge
		pair<int, int> cur = Q.top();
		Q.pop();

		int curnode = cur.second;
		// minimum weight
		int weight = cur.first;

		if (in_mst[curnode]) continue;

		// cout << curnode << " " << weight << '\n';

		in_mst[curnode] = 1;
		mst += weight;

		for (auto x : gr[curnode]) {
			int y = x.first;
			int w = x.second;

			if (!in_mst[y]) {
				Q.push({w, y});
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

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	cout << prims_mst(1);

	return 0;
}