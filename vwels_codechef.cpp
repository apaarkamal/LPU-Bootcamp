#include<bits/stdc++.h>

using namespace std;

bool is_vowel(char s) {
	return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		int i = 0, ans = 1;
		while (i < s.size()) {
			// iterate until kth vowel
			int vowels = 0;
			while (i < s.size() && vowels < k) {
				if (is_vowel(s[i])) {
					vowels++;
				}
				i++;
			}

			int j = i, conso = 0;
			while (j < s.size() && !is_vowel(s[j])) {
				j++;
				conso++;
			}
			if (j != s.size()) {
				ans = (ans * (conso + 1)) % 1000000007;
			}
			i = j;
			// cout << i << " " << j << '\n';
		}

		cout << ans << '\n';
	}


	return 0;
}