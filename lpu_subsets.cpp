#include<bits/stdc++.h>

using namespace std;

void generate_subsets(int index, string s, string result) {

	if (s.size() == index) {
		cout << result << '\n';
		return;
	}

	// exclude the current character
	generate_subsets(index + 1, s, result);

	// including the current character
	generate_subsets(index + 1, s, result + s[index]);

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	generate_subsets(0, s, "");


	return 0;
}