#include<bits/stdc++.h>

using namespace std;

struct Heap {
	vector<int> v;

	Heap(int n) {
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
	}

	// O(logn)
	void heapify(int cur) {
		int left = 2 * cur + 1;
		int right = 2 * cur + 2;

		int min_index = cur;

		if (left < v.size() && v[left] < v[min_index]) {
			min_index = left;
		}
		if (right < v.size() && v[right] < v[min_index]) {
			min_index = right;
		}

		if (min_index != cur) {
			swap(v[min_index], v[cur]);
			heapify(min_index);
		}
		return;
	}

	void print_heap() {
		for (int i = 0; i < v.size(); i++) {
			cout << i << " -> " << v[i] << '\n';
		} cout << '\n';
	}

	// O(n logn)
	void build_heap() {
		int last_child = v.size() - 1;
		int last_parent = (last_child - 1) / 2;

		for (int i = last_parent; i >= 0; i--) {
			heapify(i);
		}
	}

	int top() {
		return v[0];
	}

	int size() {
		return v.size();
	}

	bool is_empty() {
		return v.empty();
	}

	// O(logn)
	void pop() {
		swap(v[0], v[v.size() - 1]);
		// remove the last node
		v.pop_back();
		// perform heapify as other substrees are heap
		heapify(0);
	}

	// O(logn)
	void push(int x) {
		v.push_back(x);
		int idx = v.size() - 1;
		int par = (idx - 1) / 2;

		while (idx > 0 && v[par] > v[idx]) {
			swap(v[par], v[idx]);
			idx = par;
			par = (idx - 1) / 2;
		}
		return;
	}

};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	Heap H(n);
	H.build_heap();
	H.print_heap();

	// cout << H.top() << '\n';

	// H.pop();
	// H.pop();

	// cout << H.top() << '\n';

	// H.push(1);

	// cout << H.top() << '\n';

	// heap sort
	for (int i = 0; i < n; i++) {
		cout << H.top() << " ";
		H.pop();
	}

	return 0;
}