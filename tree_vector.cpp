#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int parent[N], distance[N], sz[N];


void dfs(int cur, int par) {
	parent[cur] = par;
	sz[cur] = 1;

	// cout << cur << '\n';

	for (auto adj : gr[cur]) {
		if (adj != par) {

			distance[adj] = distance[cur] + 1;

			dfs(adj, cur);

			sz[cur] += sz[adj];
		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		gr[x].push_back(y);
		gr[y].push_back(x);

	}

	// root node 1

	dfs(1, -1);

	for (int i = 1; i <= n; i++) {
		cout << i << " parent -> " << parent[i] << '\n';
	}

	return 0;
}