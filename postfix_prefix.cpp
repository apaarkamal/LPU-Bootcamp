#include<bits/stdc++.h>

using namespace std;

bool is_digit(char ch) {
	return (ch >= '0' && ch <= '9');
}

bool is_alphabet(char ch) {
	return (ch >= 'A' && ch <= 'Z')
	       || (ch >= 'a' && ch <= 'z');
}

bool is_operand(char ch) {
	return is_digit(ch) || is_alphabet(ch);
}

// postfix -> infix

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string postfix;
	cin >> postfix;

	// cout << string(6, postfix[5]) << '\n';

	stack<string> St;

	for (int i = 0; i < postfix.size(); i++) {

		if (is_operand(postfix[i])) {
			St.push(string(1, postfix[i]));
		}
		else {
			// assuming
			string operand_1 = St.top();
			St.pop();
			string operand_2 = St.top();
			St.pop();

			string result = postfix[i] + operand_2 + operand_1;

			St.push(result);
		}
	}

	cout << St.top();

	return 0;
}