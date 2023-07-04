#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N];
bool instack[N], is_cycle;

void dfs(int cur) {
	vis[cur] = 1;
	instack[cur] = true;

	for (auto adj : gr[cur]) {
		if (!vis[adj]) {
			dfs(adj);
		}
		else if (instack[adj]) {
			// backedge
			is_cycle = true;
		}
	}

	instack[cur] = false;
	return;
}

void dfswithonlyvis(int cur) {
	vis[cur] = 1;

	for (auto adj : gr[cur]) {
		if (vis[adj] == 0) {
			dfswithonlyvis(adj);
		}
		else if (vis[cur] == 1) {
			// backedge
			is_cycle = true;
		}
	}

	vis[cur] = 2;
	return;
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






	return 0;
}