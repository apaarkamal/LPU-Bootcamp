#include<bits/stdc++.h>

using namespace std;

int knapsack(int index, int n, int w, int profit[], int weight[]) {

	if (index == n || w == 0) return 0;

	// not include the current element -> index
	int value_not_including = knapsack(index + 1, n, w, profit, weight);

	int value_including = 0;
	// including the current element
	if (weight[index] <= w) {
		value_including =
		    profit[index] +
		    knapsack(index + 1, n, w - weight[index], profit, weight);
	}

	return max(value_including, value_not_including);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, w;
	cin >> n >> w;

	int profit[n], weight[n];

	for (int i = 0; i < n; i++) {
		cin >> profit[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	cout << knapsack(0, n, w, profit, weight);



	return 0;
}