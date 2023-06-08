#include<bits/stdc++.h>

using namespace std;

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		cout << i << " -> " << factorial(i) << '\n';
	}

	return 0;
}