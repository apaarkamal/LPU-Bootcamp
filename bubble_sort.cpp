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

	// bubble sort
	for (int iter = 0; iter < n - 1; iter++) {

		int sw = 0;

		for (int index = 1; index < n - iter; index++) {
			if (a[index] < a[index - 1]) {
				swap(a[index], a[index - 1]);
				sw++;
			}
		}

		// iteration ends
		if (sw == 0) break;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}