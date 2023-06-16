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

	for (int index = 1; index < n; index++) {
		int val = a[index];

		int left = index - 1;
		while (left >= 0 && a[left] > val) {
			a[left + 1] = a[left];
			left--;
		}

		// while (left >= 0 && a[left] > a[left + 1]) {
		// 	swap(a[left], a[left + 1]);
		// 	left--;
		// }

		// loop break if the value is <= current element
		// or if left = -1
		// insert to the right index
		a[left + 1] = val;

		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		} cout << '\n';

	}



	return 0;
}