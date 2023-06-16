#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n], mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	int hashh[mx + 1];
	memset(hashh, 0, sizeof(hashh));

	for (int i = 0; i < n; i++) {
		hashh[a[i]]++;
	}

	for (int i = 0; i <= mx; i++) {
		while (hashh[i]--) {
			cout << i << " ";
		}
	}




	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// } cout << '\n';

	return 0;
}