#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N];
vector<int> order;

void dfs(int cur) {
	vis[cur] = 1;
	for (auto adj : gr[cur]) {
		if (!vis[adj]) dfs(adj);
	}
	order.push_back(cur);
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
	}

	for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	reverse(order.begin(), order.end());

	for (auto x : order) cout << x << " ";




	return 0;
}