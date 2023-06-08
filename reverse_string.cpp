#include<bits/stdc++.h>

using namespace std;

void printreverse(string s) {

	if (s.empty()) return;

	string remaining = s.substr(1);

	printreverse(remaining);

	cout << s[0];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	printreverse(s);


	return 0;
}