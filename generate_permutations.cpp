#include<bits/stdc++.h>

using namespace std;

void simple_permutations(string s, string res) {

	if (s.empty()) {
		cout << res << '\n';
		return;
	}

	for (int i = 0; i < s.size(); i++) {

		string ds = s.substr(0, i) + s.substr(i + 1);

		simple_permutations(ds, res + s[i]);
	}

}

void generate_permutations(int index, string s) {

	if (index == s.size()) {
		cout << s << '\n';
		return;
	}

	for (int i = index; i < s.size(); i++) {
		// string duplicate = s;

		// swap(duplicate[i], duplicate[index]);

		swap(s[i], s[index]);

		generate_permutations(index + 1, s);

		swap(s[i], s[index]);
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	// simple_permutations(s, "");

	generate_permutations(0, s);


	return 0;
}