#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N], grr[N];
int vis[N], col[N];
vector<int> order;
vector<int> scc[N];

// O(N)
void dfs(int cur) {
	vis[cur] = 1;
	for (auto adj : gr[cur]) {
		if (!vis[adj]) dfs(adj);
	}
	order.push_back(cur);
}

// O(N)
void reverse_dfs(int cur, int component) {
	vis[cur] = 1;
	scc[component].push_back(cur);
	col[cur] = component;
	for (auto adj : grr[cur]) {
		if (!vis[adj]) reverse_dfs(adj, component);
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
		grr[y].push_back(x);
	}

	for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	reverse(order.begin(), order.end());

	memset(vis, 0, sizeof(vis));

	int strongly_component = 0;

	for (auto cur : order) {
		if (!vis[cur]) {
			strongly_component++;
			reverse_dfs(cur, strongly_component);
		}
	}

	cout << "number of scc: " << strongly_component << '\n';

	for (int i = 1; i <= strongly_component; i++) {
		for (auto x : scc[i]) cout << x << " ";
		cout << '\n';
	}

	return 0;
}