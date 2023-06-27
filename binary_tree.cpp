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

// returns root node
node* constructBinaryTree() {
	int x;
	cin >> x;
	node* root = new node(x);

	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {

		int x, y;
		cin >> x >> y;

		node* cur = Q.front();
		Q.pop();

		if (x != -1) {
			node* newnode = new node(x);
			cur->left = newnode;
			Q.push(cur->left);
		}

		if (y != -1) {
			node* newnode = new node(y);
			cur->right = newnode;
			Q.push(cur->right);
		}
	}

	return root;
}

int sizeOfTree(node* root) {
	if (root == NULL) return 0;
	return sizeOfTree(root->left)
	       + sizeOfTree(root->right) + 1;
}

int heightOfTree(node* root) {
	if (root == NULL) return 0;
	return max(heightOfTree(root->left),
	           heightOfTree(root->right)) + 1;
}

int sumTree(node* root) {
	if (root == NULL) return 0;
	return sumTree(root->left) + sumTree(root->right)
	       + root->data;
}

void bfs(node* root) {
	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		cout << cur->data << '\n';
		if (cur->left) Q.push(cur->left);
		if (cur->right) Q.push(cur->right);
	}

	return;
}

void zigzag(node* root) {
	// node*, level
	stack<node*> St_odd;
	St_odd.push(root);

	stack<node*> St_even;

	while (!St_even.empty() || !St_odd.empty()) {

		while (!St_odd.empty()) {
			// odd level
			node* cur = St_odd.top();
			cout << cur->data << '\n';
			St_odd.pop();
			if (cur->left) St_even.push(cur->left);
			if (cur->right)St_even.push(cur->right);
		}

		while (!St_even.empty()) {
			// even level
			node* cur = St_even.top();
			cout << cur->data << '\n';
			St_even.pop();
			if (cur->right) St_odd.push(cur->right);
			if (cur->left) St_odd.push(cur->left);
		}

	}
	return;
}

void dfs(node* root) {
	if (root == NULL) return;
	// cout << root->data << '\n';
	dfs(root->left);
	dfs(root->right);
	// cout << root->data << '\n';
	return;
}

// preorder
void preorder(node* root) {
	if (root == NULL) return;
	// preorder
	cout << root->data << '\n';
	preorder(root->left);
	preorder(root->right);
	return;
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
	cout << root->data << '\n';
	postorder(root->right);
	return;
}


int leftsumTree(node* root) {
	if (root == NULL) return 0;
	int sumleft = leftsumTree(root->left);
	int sumright = leftsumTree(root->right);
	cout << sumleft << '\n';
	return sumleft + sumright + root->data;
}

void leftView(node* root) {
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	cout << root->data;

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			// its was the last element of previous lvl
			if (!Q.empty()) {
				cout << Q.front() << " ";
				Q.push(NULL);
			}
		}
		else {
			//
			if (cur->left) Q.push(cur->left);
			if (cur->right) Q.push(cur->right);
		}
	}
}

void rightView(node* root) {
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	cout << root->data;

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			// its was the last element of previous lvl
			if (!Q.empty()) {
				cout << Q.front() << " ";
				Q.push(NULL);
			}
		}
		else {
			// swap for right view
			if (cur->right) Q.push(cur->right);
			if (cur->left) Q.push(cur->left);
		}
	}
}

void topView(node* root) {
	// int -> shift
	queue<pair<node*, int>> Q;
	Q.push({root, 0});
	map<int, int> mp;

	while (!Q.empty()) {
		pair<node*, int> cur = Q.front();
		Q.pop();

		if (!mp.count(cur.second)) {
			mp[cur.second] = cur.first->data;
		}

		if (cur.first->left) {
			Q.push({cur.first->left, cur.second - 1});
		}
		if (cur.first->right) {
			Q.push({cur.first->right, cur.second + 1});
		}
	}

	for (auto x : mp) {
		cout << x.second << " ";
	}
}

void bottomView(node* root) {
	// int -> shift
	queue<pair<node*, int>> Q;
	Q.push({root, 0});
	map<int, int> mp;

	while (!Q.empty()) {
		pair<node*, int> cur = Q.front();
		Q.pop();

		mp[cur.second] = cur.first->data;

		if (cur.first->left) {
			Q.push({cur.first->left, cur.second - 1});
		}
		if (cur.first->right) {
			Q.push({cur.first->right, cur.second + 1});
		}
	}

	for (auto x : mp) {
		cout << x.second << " ";
	}
}

bool is_identical(node* root1, node* root2) {
	if (root1 == NULL || root2 == NULL) {
		return (root1 == root2);
	}
	return is_identical(root1->left, root2->left)
	       && is_identical(root1->right, root2->right)
	       && (root1->data == root2->data);
}

bool is_mirror(node* root1, node* root2) {
	if (root1 == NULL || root2 == NULL) {
		return (root1 == root2);
	}
	return is_mirror(root1->left, root2->right)
	       && is_mirror(root1->right, root2->left)
	       && (root1->data == root2->data);
}

node* mirrorTree(node* root) {
	if (root == NULL) return NULL;
	mirrorTree(root->left);
	mirrorTree(root->right);
	swap(root->left, root->right);
	return root;
}

int diameter(node* root) {
	if (root == NULL) return 0;

	// either the diameter passes
	// through the current node
	int dia1 = heightOfTree(root->left)
	           + heightOfTree(root->right);

	int dialeft = diameter(root->left);
	int diaright = diameter(root->right);

	return max({dia1, dialeft, diaright});
}

node* constructusingpreorder() {
	int x;
	cin >> x;
	if (x == -1) return NULL;


	node* root = new node(x);
	root->left = constructusingpreorder();
	root->right = constructusingpreorder();

	return root;
}

node* constructusinginorder() {
	int x;
	cin >> x;
	if (x == -1) return NULL;


	root->left = constructusingpreorder();
	node* root = new node(x);
	root->right = constructusingpreorder();

	return root;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// node* root = constructBinaryTree();
	// node* root = constructusingpreorder();
	node* root = constructusinginorder();

	// node* root2 = constructBinaryTree();

	// cout << root->left->right->data;

	// cout << sizeOfTree(root);

	// cout << heightOfTree(root);

	// bfs(root);

	// zigzag(root);

	// leftView(root);

	// topView(root);

	// bottomView(root);

	// cout << is_identical(root1, root2);

	// cout << is_mirror(root1, root2);

	// preorder(root1);

	// node* root3 = mirrorTree(root1);

	// preorder(root3);

	// cout << is_mirror(root1, root2);

	// cout << diameter(root);

	preorder(root);



	return 0;
}