#include<bits/stdc++.h>

using namespace std;

void print1ton(int n) {
	if (n <= 0) return;

	cout << n;

	print1ton(n - 2);

	cout << n;

	print1ton(n - 1);

	cout << n;

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	print1ton(n);


	return 0;
}