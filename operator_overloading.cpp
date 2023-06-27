#include<bits/stdc++.h>

using namespace std;

struct node {
	int age;
	string name;

	node(int _age, string _name) {
		this->age = _age;
		this->name = _name;
	}

	// operator overloading
	bool operator==(node b) {
		if (this->name == b.name && this->age == b.age) {
			return true;
		}
		return false;
	}

	// operator overloading
	bool operator<(node b) {
		if (this->age < b.age) {
			return true;
		}
		return false;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	node a(23, "apaar");

	node b(19, "amit");

	// cout << a.name;

	if (a == b) {
		cout << "they are the same person\n";
	}
	else {
		cout << "they are not same\n";
	}

	if (a < b) {
		cout << "yes, a's age is less\n";
	}
	else {
		cout << "not less\n";
	}


	return 0;
}