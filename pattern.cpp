#include<bits/stdc++.h>

using namespace std;

void printrighthalfpyramid(int stars, int total) {
	if (stars == 0) return;

	printrighthalfpyramid(stars - 1, total);

	// white spaces
	int _white = total - stars;
	while (_white--) cout << " ";

	// print the stars
	int _stars = stars;
	while (_stars--) cout << "*";
	cout << '\n';

}

void printlefthalfpyramid(int stars, int total) {
	if (stars == 0) return;

	// white spaces
	int _white = total - stars;
	while (_white--) cout << " ";

	// print the stars
	int _stars = stars;
	while (_stars--) cout << "*";
	cout << '\n';

	printlefthalfpyramid(stars - 1, total);
}

void printrightfullpyramid(int stars, int total) {
	if (stars == 0) return;

	// white spaces
	int _white = total - stars;
	while (_white--) cout << " ";

	// print the stars
	int _stars = stars;
	while (_stars--) cout << " *";
	cout << '\n';

	printrightfullpyramid(stars - 1, total);

	// white spaces
	_white = total - stars;
	while (_white--) cout << " ";

	// print the stars
	_stars = stars;
	while (_stars--) cout << " *";
	cout << '\n';
}

void printcharacter(string s, int n) {
	while (n--) cout << s;
}

void printhollowsquare(int stars, int total) {

	// cout << stars << " " << total << '\n';

	if (stars == 0) return;

	if (stars == total || stars == 1) {
		printcharacter("*", total);
		cout << '\n';
	}
	else {
		printcharacter("*", 1);
		printcharacter(" ", total - 2);
		printcharacter("*", 1);
		cout << '\n';
	}

	printhollowsquare(stars - 1, total);
}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int total;
	cin >> total;

	// print(total, total);

	// printlefthalfpyramid(total, total);

	printhollowsquare(total, total);
	return 0;
}