#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N], color[N];

void dfs(int cur, int component) {
	vis[cur] = 1;
	color[cur] = component;

	for (auto adj : gr[cur]) {
		if (!vis[adj]) {
			dfs(adj, component);
		}
	}
}

void bfs(int source, int component) {
	queue<int> Q;
	Q.push(source);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		vis[cur] = 1;
		color[cur] = component;

		for (auto adj : gr[cur]) {
			if (!vis[adj]) {
				Q.push(adj);
			}
		}
	}

	return;
}

bool is_sameComponent(int x, int y) {
	return (color[x] == color[y]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	int component = 0;

	for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) {
			component++;
			// dfs(i, component);
			bfs(i, component);
		}
	}

	for (int i = 1; i < nodes; i++) {
		cout << i << " " << color[i] << '\n';
	}

	// cout << is_sameComponent(1, 5);

	cout << component;

	return 0;
}