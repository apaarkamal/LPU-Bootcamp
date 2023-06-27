#include<bits/stdc++.h>

using namespace std;

void push_at_bottom(stack<int> &St, int x) {
	if (St.empty()) {
		St.push(x);
		return;
	}

	int y = St.top();
	St.pop();

	push_at_bottom(St, x);

	St.push(y);
}

void reverse(stack<int> &St) {
	if (St.empty()) return;

	int x = St.top();

	St.pop();

	reverse(St);

	// push at the bottom
	push_at_bottom(St, x);

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	stack<int> St;

	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);

	reverse(St);

	while (!St.empty()) {
		cout << St.top() << " ";
		St.pop();
	} cout << '\n';

	return 0;
}