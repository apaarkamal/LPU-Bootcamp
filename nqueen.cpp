#include<bits/stdc++.h>

using namespace std;

const int N = 14;

int grid[N][N], cnt = 0;

void print_grid() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 1) {
				cout << "Q";
			}
			else {
				cout << ".";
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

// try and check if a queen can be placed in the
// cell[row][col]
bool is_safe(int row, int col) {
	int _row = row, _col = col;

	// check in the same column
	while (_row >= 0) {
		if (grid[_row][_col]) return false;
		_row--;
	}

	// left diagonal
	_row = row, _col = col;
	while (_row >= 0 && _col >= 0) {
		if (grid[_row][_col]) return false;
		_row--; _col--;
	}

	// right diagonal
	_row = row, _col = col;
	while (_row >= 0 && _col < N) {
		if (grid[_row][_col]) return false;
		_row--; _col++;
	}

	return true;
}

void nqueen(int row) {

	// base case
	if (row == N) {
		// placed all N queens
		cnt++;
		// print_grid();
		return;
	}

	for (int col = 0; col < N; col++) {
		// try and place the queen
		if (is_safe(row, col)) {
			// placing a queen
			grid[row][col] = 1;

			// print_grid();

			// try and place in the next row
			nqueen(row + 1);

			// backtrack
			grid[row][col] = 0;

			// print_grid();
		}
	}

	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	nqueen(0);

	cout << cnt;

	return 0;
}