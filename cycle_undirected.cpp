#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N], color[N];

bool is_cycle(int cur, int par = -1) {
	vis[cur] = 1;
	bool cycle = false;

	for (auto adj : gr[cur]) {
		if (!vis[adj]) {
			cycle |= is_cycle(adj, cur);
		}
		else if (adj != par) {
			// visited
			//  backedge
			cycle = true;
		}
	}

	return cycle;
}

bool odd_cycle(int cur, int par, int col) {
	vis[cur] = 1;
	color[cur] = col;

	bool odd_cycle_found = false;

	for (auto adj : gr[cur]) {
		if (!vis[adj]) {
			odd_cycle_found |= odd_cycle(adj, cur, 1 - col);
		}
		else if (color[adj] == color[cur]) {
			// backedge
			odd_cycle_found = true;
		}
	}

	return odd_cycle_found;
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

	for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) {
			// bool cycle = is_cycle(i);
			bool odd_cycle_found = odd_cycle(i, -1, 0);
			// if (cycle) {
			// 	cout << "cycle found\n";
			// }
			if (odd_cycle_found) {
				cout << "odd cycle found\n";
			}
		}
	}






	return 0;
}