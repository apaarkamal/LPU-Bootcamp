#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string s, p;
	vector<vector<int>> memo;
	bool dp(int i, int j) {
		if (i == s.size() && j == p.size()) return true;
		if (j == p.size()) return false;

		// j<p.size()
		// i<=s.size()
		if (memo[i][j] != -1) return memo[i][j];

		bool ans = false;
		if (j + 1 < p.size() && p[j + 1] == '*') {
			// zero match
			ans |= dp(i, j + 2);
			if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
				// dont increase j so that it can match again
				ans |= dp(i + 1, j);
			}
		}
		else {
			if (i < s.size() && (s[i] == p[j] || p[j] == '.')) {
				// match exactly once
				ans |= dp(i + 1, j + 1);
			}
		}
		return  memo[i][j] = ans;
	}
	bool isMatch(string s, string p) {
		this->s = s;
		this->p = p;
		memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
		return dp(0, 0);
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution H;
	cout << H.isMatch("aa", "a*");


	return 0;
}