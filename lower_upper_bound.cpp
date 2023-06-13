#include<bits/stdc++.h>

using namespace std;

int binarysearch(int a[], int x, int left, int right) {
	if (left > right) return -1;

	int mid = (left + right) / 2;
	if (a[mid] == x) {
		return mid;
	}
	else if (a[mid] < x) {
		// right part
		return binarysearch(a, x, mid + 1, right);
	}
	else {
		// left part
		return binarysearch(a, x, left, mid - 1);
	}
}

int lowerBound(int a[], int x, int n) {
	int left = 0, right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		if (x <= a[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	// loop breaks left = right = lower bound

	return left;
}

int upperBound(int a[], int x, int n) {
	int left = 0, right = n;

	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] <= x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	// loop breaks left = right = upper bound

	return left;
}

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

	cout << "lower bound -> " << lowerBound(a, x, n) << '\n';

	cout << "upper bound -> " << upperBound(a, x, n) << '\n';

	cout << "total occurence of " << x << " -> " << upperBound(a, x, n) - lowerBound(a, x, n);








	return 0;
}