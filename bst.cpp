#include<bits/stdc++.h>

using namespace std;

struct node {
	node *left, *right;
	int data;
	node(int data) {
		left = right = NULL;
		this->data = data;
	}
};

bool searchInBST(node* root, int x) {
	if (root == NULL) return false;
	if (x < root->data) {
		return searchInBST(root->left, x);
	}
	else if (x > root->data) {
		return searchInBST(root->right, x);
	}
	else {
		return true;
	}
}

node* insertInBST(node* root, int x) {
	if (root == NULL) return new node(x);

	if (x < root->data) {
		root->left = insertInBST(root->left, x);
	}
	else {
		root->right = insertInBST(root->right, x);
	}

	return root;
}

node* buildBST() {
	int x;
	cin >> x;
	node* root = NULL;

	while (x != -1) {
		// cout << x << '\n';
		root = insertInBST(root, x);
		cin >> x;
	}

	return root;
}

// inorder
void inorder(node* root) {
	if (root == NULL) return;
	// inorder
	inorder(root->left);
	cout << root->data << '\n';
	inorder(root->right);
	return;
}

// postorder
void postorder(node* root) {
	if (root == NULL) return;
	// postorder
	postorder(root->left);
	postorder(root->right);
	cout << root->data << '\n';
	return;
}

node* deleteInBst(node* root, int x) {
	if (root == NULL) return NULL;

	if (x < root->data) {
		root->left = deleteInBst(root->left, x);
	}
	else if (x > root->data) {
		root->right = deleteInBst(root->right, x);
	}
	else {
		// delete the cur node

		// leaf
		if (root->left == NULL && root->right == NULL) {
			return NULL;
		}
		else if (root->left != NULL && root->right == NULL) {
			// left child node
			return root->left;
		}
		else if (root->left == NULL && root->right != NULL) {
			// left child node
			return root->right;
		}
		else {
			// two child node
			node* temp = root->left;
			while (temp->right != NULL) {
				temp = temp->right;
			}
			temp->right = root->right;
			return root->left;
		}
	}

	return root;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	node* root = buildBST();

	inorder(root);

	cout << '\n';

	// cout << searchInBST(root, 11);

	root = deleteInBst(root, 10);

	inorder(root);

	return 0;
}