#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Stack {
private:
	struct node {
		T data;
		node* next;
		node(T _data) {
			this->data = _data;
			this->next = NULL;
		}
	}* head;
public:
	Stack() {
		head = NULL;
	}

	bool is_empty() {
		return head == NULL;
	}

	void push(T x) {
		node* newnode = new node(x);
		newnode->next = head;
		head = newnode;
	}

	T top() {
		// if (head == NULL) return -1;
		return head->data;
	}

	void pop() {
		if (head == NULL) return;
		node* tobe_deleted = head;
		head = head->next;
		delete tobe_deleted;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Stack<int> St;

	St.push(10);
	St.push(9);
	cout << St.top() << '\n';

	St.pop();

	cout << St.top() << '\n';

	St.push(11);

	cout << St.top() << '\n';


	return 0;
}