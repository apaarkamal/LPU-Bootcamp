#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int x;
	cin >> x;

	int index = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			index = i;
			// break;
		}
	}

	cout << index;

	return 0;
}