#include<bits/stdc++.h>

using namespace std;

const int N = 10;

class Stack {
private:
	int a[N], top_index;
public:
	Stack() {
		top_index = -1;
	}

	bool is_empty() {
		return (top_index == -1);
	}

	bool is_full() {
		return (top_index == N - 1);
	}

	void push(int x) {
		if (is_full()) {
			cout << "stack is full\n";
			return;
		}
		top_index++;
		a[top_index] = x;
	}

	int top() {
		if (is_empty()) {
			return -1;
		}
		return a[top_index];
	}

	void pop() {
		if (is_empty()) {
			cout << "cannot pop, stack is empty\n";
			return;
		}
		top_index--;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Stack S;

	S.push(5);
	S.push(6);
	cout << S.top() << '\n';
	S.push(7);
	S.push(8);

	cout << S.top() << '\n';

	S.pop();

	cout << S.top() << '\n';

	S.pop();
	S.pop();
	S.pop();
	S.pop();
	S.pop();



	return 0;
}