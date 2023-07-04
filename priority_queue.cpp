#include<bits/stdc++.h>

using namespace std;

class compare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	priority_queue<int, vector<int>, compare> Q;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		Q.push(x);
	}

	while (!Q.empty()) {
		cout << Q.top() << " ";
		Q.pop();
	}


	return 0;
}