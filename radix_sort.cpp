#include<bits/stdc++.h>

using namespace std;

int cnt_digits(int x) {
	int cnt = 0;
	while (x) {
		cnt++;
		x = x / 10;
	}
	return cnt;
}

int find_max_digit(int a[], int n) {
	int mx_digit = 0;
	for (int i = 0; i < n; i++) {
		mx_digit = max(mx_digit, cnt_digits(a[i]));
	}
	return mx_digit;
}

// i=0 ones
// i=1 means tens place
// O(10*n)
void count_sort(int a[], int n, int radix) {

	vector<int> count[10];
	for (int i = 0; i < n; i++) {
		int power_10 = pow(10, radix);
		int digit = (a[i] / power_10) % 10;
		count[digit].push_back(a[i]);
	}

	int k = 0;
	for (int i = 0; i < 10; i++) {
		// count[i]
		for (int j = 0; j < count[i].size(); j++) {
			// count[i][j]
			// copy[i][j] back to a[k]
			a[k] = count[i][j];
			k++;
		}
	}
}

// O(n * 10 * mx_digit)
void radix_sort(int a[], int n) {
	// O(n)
	int mx_digit = find_max_digit(a, n);

	//
	for (int i = 0; i < mx_digit; i++) {
		count_sort(a, n, i);
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

	radix_sort(a, n);
	// count_sort(a, n, 0);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}