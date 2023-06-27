#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n], next_larger[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// value, index
	stack<pair<int, int>> St;

	for (int i = n - 1; i >= 0; i--) {

		while (!St.empty() && St.top().first < a[i]) {
			next_larger[St.top().second] = i;
			St.pop();
		}

		St.push({a[i], i});
	}

	// there larger element to the left doe not exist
	while (!St.empty()) {
		next_larger[St.top().second] = -1;
		St.pop();
	}




	return 0;
}