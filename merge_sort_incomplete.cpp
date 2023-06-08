#include<bits/stdc++.h>

using namespace std;
//
void mergearray(int a[], int l1, int r1, int l2, int r2) {

}

void mergeSort(int a[], int start, int end) {

	if (start == end) {
		return;
	}

	int middle = (end + start) / 2;

	mergeSort(a, start, middle);
	mergeSort(a, middle + 1, end);

	// (start - middle)
	// (middle+1, end)
	mergearray(a, start, middle, middle + 1, end);

	return;
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

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


	return 0;
}