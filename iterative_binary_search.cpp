#include<bits/stdc++.h>

using namespace std;

// iterative binary search

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, x;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> x;

	sort(a, a + n);

	int left = 0, right = n - 1, index = -1;
	bool found = false;

	// keep binary searching until the range is valid
	while (left <= right) {
		int middle = (left + right) / 2;
		if (a[middle] == x) {
			found = true;
			index = middle;
			break;
		}
		else if (a[middle] < x) {
			left = middle + 1;
		}
		else if (a[middle] > x) {
			right = middle - 1;
		}
	}

	if (found) cout << "found at index -> " << index ;
	else cout << "not found";












	return 0;
}