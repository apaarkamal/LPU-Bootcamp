#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	// Time Complexity O(n)
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		vector<int> l_sm_id(n), r_sm_id(n), area(n);
		stack<int> St;

		for (int i = 0; i < n; i++) {
			while (!St.empty()
			        && heights[St.top()] > heights[i]) {
				r_sm_id[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}
		while (!St.empty()) {
			r_sm_id[St.top()] = n;
			St.pop();
		}

		// l_sm_id
		for (int i = n - 1; i >= 0; i--) {
			while (!St.empty()
			        && heights[St.top()] > heights[i]) {
				l_sm_id[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}
		while (!St.empty()) {
			l_sm_id[St.top()] = -1;
			St.pop();
		}

		for (int i = 0; i < n; i++) {
			area[i] = heights[i]
			          * (r_sm_id[i] - l_sm_id[i] - 1);
		}

		return *max_element(area.begin(), area.end());
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<int> v = {2, 1, 5, 6, 2, 3};

	Solution H;
	cout << H.largestRectangleArea(v);



	return 0;
}