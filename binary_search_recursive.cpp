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

	int left = 0, right = n - 1;

	int index = binarysearch(a, x, 0, n - 1);


	if (index == -1) cout << "not found";
	else cout << "found at idnex -> " << index;












	return 0;
}