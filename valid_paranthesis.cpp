#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> St;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				St.push(s[i]);
			}
			else {
				if (St.empty()) return false;
				char open = St.top();
				St.pop();

				if (s[i] == ')' && open != '(') return false;
				if (s[i] == '}' && open != '{') return false;
				if (s[i] == ']' && open != '[') return false;
			}
		}

		return St.empty();
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	cin >> s;

	Solution H;

	cout << H.isValid(s);

	return 0;
}