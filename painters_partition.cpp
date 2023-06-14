#include<bits/stdc++.h>

using namespace std;

int painter_required(int a[], int max_time, int n) {
	int painters = 1;
	int blocks_of_current_painter = a[0];

	for (int i = 1; i < n; i++) {
		if (blocks_of_current_painter + a[i] <= max_time) {
			blocks_of_current_painter += a[i];
		}
		else {
			painters++;
			blocks_of_current_painter = a[i];
		}
	}
	return painters;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, sum = 0, mx = 0, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}

	// cout << painter_required(a, 40, n);

	int left = mx, right = sum;

	while (left < right) {
		int mid = (left + right) / 2;
		if (painter_required(a, mid, n) <= k) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left;





	return 0;
}