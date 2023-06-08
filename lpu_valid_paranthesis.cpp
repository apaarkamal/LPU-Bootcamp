#include<bits/stdc++.h>

using namespace std;

// index, resultant string, open, closing, n
void valid_paranthesis(
    int index, string res,
    int open, int close, int n) {

	if (index == n) {
		cout << res << '\n';
		return;
	}

	// either add a opening bracket
	if (open < n / 2) {
		valid_paranthesis(index + 1, res + "(", open + 1, close, n);
	}

	// add a closing bracket
	if (close < open) {
		valid_paranthesis(index + 1, res + ")", open, close + 1, n);
	}

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	string res = "";

	valid_paranthesis(0, res, 0, 0, n);

	return 0;
}