#include<bits/stdc++.h>

using namespace std;

// O(n)
int place_cows(int a[], int n, int min_dis) {
	// place first cow at a[0]
	int cows = 1, prev_cow = a[0];

	for (int i = 1; i < n; i++) {
		// try and place a cow at index i
		if (a[i] - prev_cow >= min_dis) {
			cows++;
			prev_cow = a[i];
		}
	}

	return cows;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		int left = 1, right = 1e9, ans = 1;

		// left = 29
		// right = 30
		while (left < right) {
			// 29
			int mid = (left + right) / 2;
			// cout << mid << '\n';
			if (place_cows(a, n, mid) >= c) {
				// 29
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		cout << ans;

	}


	return 0;
}