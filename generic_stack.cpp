#include<bits/stdc++.h>

using namespace std;

const int N = 10;

template<typename T>
class Stack {
private:
	T a[N];
	int top_index;
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

	void push(T x) {
		if (is_full()) {
			cout << "stack is full\n";
			return;
		}
		top_index++;
		a[top_index] = x;
	}

	T top() {
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

	Stack<string> S;

	S.push("abf");
	S.push("das");
	S.push("fdsf");
	S.push("daasd");

	cout << S.top() << '\n';

	S.pop();

	cout << S.top() << '\n';

	return 0;
}