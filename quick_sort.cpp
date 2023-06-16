#include<bits/stdc++.h>

using namespace std;

int partition(int a[], int left, int right) {
	int pivot = a[right];

	int i = left;

	for (int j = left; j < right; j++) {
		if (a[j] < pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}

	// make pivot come at right place
	swap(a[i], a[right]);
	return i;
}

void quicksort(int a[], int left, int right) {
	if (left < right) {
		// partition
		int pi = partition(a, left, right);

		quicksort(a, left, pi - 1);
		quicksort(a, pi + 1, right);
	}
}

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

	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}