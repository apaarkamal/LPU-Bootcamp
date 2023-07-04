#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int dis[N], vis[N];

void multisource_bfs(vector<int> sources) {
	queue<int> Q;
	for (auto source : sources) {
		Q.push(source);
		dis[source] = 0;
		vis[source] = 1;
	}

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (auto adj : gr[cur]) {
			if (!vis[adj]) {
				vis[adj] = 1;
				dis[adj] = dis[cur] + 1;
				Q.push(adj);
			}
		}
	}
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

	vector<int> sources = {1, 4};

	multisource_bfs(sources);

	for (int i = 1; i <= nodes; i++) {
		cout << i << " " << dis[i] << '\n';
	}







	return 0;
}