#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string prefix;
	cin >> prefix;

	stack<string> St;

	// *-a/bc-/akl -> abc/-ak/l-*
	for (int i = prefix.size() - 1; i >= 0; i--) {
		if (isalnum(prefix[i])) {
			// operand
			St.push(string(1, prefix[i]));
		}
		else {
			string op1 = St.top();
			St.pop();
			string op2 = St.top();
			St.pop();

			string result = op1 + op2 + prefix[i];

			St.push(result);
		}
	}

	cout << St.top();

	return 0;
}