#include<bits/stdc++.h>

using namespace std;

// O(2^n)

// please add memo to this??
// unique states?? -> i*j O(n^2)

int dp(int i, int j, int price[], int n) {
	int year = n + i - j;

	if (i == j) return price[i] * year;

	return max(
	           // picking ith element
	           dp(i + 1, j, price, n) + year * price[i],
	           dp(i, j - 1, price, n) + year * price[j]
	       );
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int price[n];

	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	cout << dp(0, n - 1, price, n);


	return 0;
}