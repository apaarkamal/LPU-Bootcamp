#include<bits/stdc++.h>

using namespace std;

// void square(int &m) {
// 	// cout << &n << '\n';
// 	m = m * m;
// }

// return true if a should come first then b
// ptherwise false
bool comp(pair<int, int> a, pair<int, int> b) {
	// compare the second element
	if (a.first == b.first) {
		// return the highest first
		return a.second > b.second;
	}

	// compare the first element
	// return the lowest first
	return a.first < b.first;
}

// a come first then b
bool desc(int a, int b) {
	return a > b;
}

bool square_sort(int a, int b) {
	return (a * a) + a < (b * b) + b;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// cout << comp({1, 2}, {1, 3});

	// int n = 10;

	// cout << &n << '\n';

	// int *p = &n;

	// cout << *p << '\n';

	// square(n);

	// cout << n;

	// int *p = nullptr;

	// int a[5] = {1, 2, 3, 4, 5};

	// cout << a[0];
	// *(p+0)

	// int *p = a;

	// cout << *p << '\n';

	// cout << *(p + 2) << '\n';

	int a[5] = { -2, 3, -6, 4, -1};

	// sort (LB, UB)
	// [LB, UB)
	// sort(a, a + 5, desc);

	sort(a, a + 5, square_sort());

	// reverse(a + 2, a + 4);

	for (int i = 0; i < 5; i++) cout << a[i] << " ";

	// comparators
	// int n;
	// cin >> n;
	// pair<int, int> a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i].first >> a[i].second;
	// }

	// sort(a, a + n, comp);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].first << " " << a[i].second << '\n';
	// }





	return 0;
}