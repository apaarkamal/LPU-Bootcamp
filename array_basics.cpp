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

	// int _max = INT_MIN;

	// for (int i = 0; i < n; i++) {
	// 	_max = max(_max, a[i]);
	// }

	int index = min_element(a, a + n) - a;

	cout << index;

	// bool is_sorted = 1;
	// for (int i = 0; i < n - 1; i++) {
	// 	is_sorted &= (a[i] <= a[i + 1]);
	// }

	// cout << is_sorted;

	// vector sort check
	// int n;
	// cin >> n;
	// vector<int> a(n), b(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }

	// b = a;
	// sort(b.begin(), b.end());

	// if (a == b) cout << "a was sorted";
	// else "not sorted";







	return 0;
}