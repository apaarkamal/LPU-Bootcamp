#include<bits/stdc++.h>

using namespace std;

int sum(string s) {
	if (s.empty()) return 0;

	int first_number = (s[0] - '0');

	string remaining_string = s.substr(1);

	return first_number + sum(remaining_string);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	cout << sum(s);

	// int a = s[0];

	// cout << a;


	return 0;
}