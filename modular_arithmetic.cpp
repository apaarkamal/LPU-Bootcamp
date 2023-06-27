#include<bits/stdc++.h>
#define int long long int

using namespace std;

// modulo template starts
int M = 1e6 + 3;
const int N = 1e6 + 1;

// store fact[i]%M
int fact[N];

// binary exponentiation
int bin_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2 == 1) {
			// odd number -> last bit set
			res = (res * a) % M;
		}
		a = (a * a) % M;
		b = b / 2;
	}
	return res;
}

int inv(int x) {
	return bin_pow(x, M - 2);
}

int add(int a, int b) {return (a % M + b % M) % M;}
int sub(int a, int b) {return ((a % M - b % M) + M) % M;}
int mul(int a, int b) {return ((a % M) * (b % M)) % M;}
int dvd(int a, int b) {return mul(a, inv(b));}
// modulo template ends

// precompute factorials % M till N
void compute_factorials() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
}

// O(1)
int nCk(int n, int k) {
	if (k == 0) return 1;
	return mul(fact[n], mul(inv(fact[k]), inv(fact[n - k])));
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	compute_factorials();

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << nCk(n, k) << '\n';
	}

	return 0;
}