#include<bits/stdc++.h>

using namespace std;

struct trie {
	trie* next[26];
	bool is_end;
	int cnt;

	trie() {
		is_end = false;
		cnt = 0;
		for (int i = 0; i < 26; i++) next[i] = NULL;
	}
};

void insert(trie* root, string name) {
	trie* cur = root;
	cur->cnt++;

	for (int i = 0; i < name.size(); i++) {
		char ch = name[i];
		int val = (ch - 'a');

		if (cur->next[val] == NULL) {
			cur->next[val] = new trie();
		}

		cur = cur->next[val];
		cur->cnt++;
	}

	// cur??
	cur->is_end = true;
}

bool findInTrie(trie* root, string name) {
	trie* cur = root;

	for (int i = 0; i < name.size(); i++) {
		char ch = name[i];
		int val = (ch - 'a');

		if (cur->next[val] == NULL) return false;

		cur = cur->next[val];
	}

	return cur->is_end;
}

int cntOfNamesWithPrefix(trie* root, string prefix) {
	trie* cur = root;

	for (int i = 0; i < name.size(); i++) {
		char ch = name[i];
		int val = (ch - 'a');

		if (cur->next[val] == NULL) return 0;

		cur = cur->next[val];
	}

	return cur->cnt;
}


// search substring a string in O(size(substring))



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	trie* root = new trie();

	insert(root, "apaar");
	insert(root, "apa");
	insert(root, "kamal");
	insert(root, "a");

	// cout << findInTrie(root, "apapa");

	cout << cntOfNamesWithPrefix(root, "a");


	return 0;
}