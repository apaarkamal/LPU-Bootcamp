#include<bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
	if (n <= 2) return n - 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << i << " -> " << fibonacci(i) << '\n';
	}

	return 0;
}