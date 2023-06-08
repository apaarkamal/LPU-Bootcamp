#include<bits/stdc++.h>

using namespace std;

bool palindrome(string s) {

	if (s.size() <= 1) return true;

	bool first_last = (s[0] == s[s.size() - 1]);

	string substring = s.substr(1, s.size() - 2);

	return first_last && palindrome(substring);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	cout << palindrome(s);


	return 0;
}