#include<bits/stdc++.h>

using namespace std;

const int N = 10;

class Queue {
private:
	int a[N], front, rear, cnt;
public:
	Queue() {
		front = 0;
		rear = -1;
		cnt = 0;
	}

	bool full() {
		return (cnt == N);
	}

	bool empty() {
		return (cnt == 0);
	}

	void push(int x) {
		if (full()) return;
		rear++;
		rear %= N;
		cnt++;
		a[rear] = x;
	}

	int at_front() {
		if (empty()) return -1;
		return a[front];
	}

	void pop() {
		if (empty()) return;
		front++;
		front %= N;
		cnt--;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Queue Q;

	Q.push(5);

	cout << Q.at_front() << '\n';

	Q.push(6);
	Q.pop();

	cout << Q.at_front() << '\n';

	return 0;
}