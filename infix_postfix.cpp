#include<bits/stdc++.h>

using namespace std;


int prec(char ch) {
	if (ch == '^') {
		return 3;
	}
	else if (ch == '*' || ch == '/') {
		return 2;
	}
	else {
		return 1;
	}
}

bool is_left_associative(char ch) {
	return (prec(ch) <= 2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string infix;
	cin >> infix;

	string postfix;
	stack<char> St;

	for (char op : infix) {
		if (isalnum(op)) {
			// operand
			postfix += op;
		}
		else {
			// operator

			if (op == '(') {
				// opening bracket
				St.push('(');
			}
			else if (op == ')') {
				// closing brracket
				while (St.top() != '(') {
					postfix += St.top();
					St.pop();
				}
				St.pop();
			}
			else {
				// +, -, *, /, ^
				// precedence is less
				while (!St.empty()
				        && St.top() != '('
				        && prec(op) < prec(St.top())) {
					postfix += St.top();
					St.pop();
				}

				// precedence is same
				// left associative
				while (!St.empty()
				        && St.top() != '('
				        && prec(op) == prec(St.top())
				        && is_left_associative(op)) {
					postfix += St.top();
					St.pop();
				}

				St.push(op);
			}
		}
	}

	while (!St.empty()) {
		postfix += St.top();
		St.pop();
	}

	cout << postfix;

	return 0;
}