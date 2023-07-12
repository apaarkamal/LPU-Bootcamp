#include<bits/stdc++.h>

using namespace std;

// memoise based on heads and tails O(n^2) ??
// homework
double dp(int i, int heads, int tails, double p[]) {
	if (heads == 0 && tails == 0) return 1.00;

	double ans = 0;
	// current toss heads
	if (heads > 0) {
		ans += dp(i + 1, heads - 1, tails, p) * p[i];
	}

	// current chance me tails
	if (tails > 0) {
		ans += dp(i + 1, heads, tails - 1, p) * (1 - p[i]);
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	double p[n];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	double ans = 0;

	for (int heads = (n / 2 + 1); heads <= n; heads++) {
		ans += dp(0, heads, n - heads, p);
	}

	cout << setprecision(10) << fixed;

	cout << ans;

	return 0;
}