#include<bits/stdc++.h>

using namespace std;

// linked list structure
struct node {
	int data;
	node *next;

	node(int _data) {
		this->data = _data;
		this->next = NULL;
	}
};

// O(n)
node* construct_ll() {
	int n;
	cin >> n;
	node *head = NULL, *tail = NULL;

	while (n--) {
		int x;
		cin >> x;
		node *temp = new node(x);
		if (head == NULL) {
			// first node
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	return head;
}

// O(n)
void printll(node *head) {
	node* cur = head;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
	return;
}

void printlladdressed(node *head) {
	node* cur = head;
	while (cur) {
		cout << cur << " ";
		cur = cur->next;
	}
	cout << '\n';
	return;
}

// todo
// void createll_endwith_minusone

// O(1)
node* insertAtHead(node *head, int x) {
	node *cur = new node(x);
	if (head != NULL) {
		cur->next = head;
	}
	head = cur;
	return head;
}

// O(n)
node* insertAtTail(node *head, int x) {
	if (head == NULL) {
		return insertAtHead(head, x);
	}
	node *cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	// cur = tail
	node *newnode = new node(x);
	cur->next = newnode;
	return head;
}

int lengthOfLL(node* head) {
	int length = 0;
	node* cur = head;
	while (cur) {
		length++;
		cur = cur->next;
	}
	return length;
}

// k is 1 based indexed
// if  k==1 insert at head
node *insertAtK(node* head, int x, int k) {
	if (k == 1) {
		return insertAtHead(head, x);
	}
	if (k > lengthOfLL(head)) {
		return insertAtTail(head, x);
	}
	k -= 2;
	node *cur = head;
	while (k--) {
		cur = cur->next;
	}
	// cur is pointing to the k-1th node
	node *newnode = new node(x);
	newnode->next = cur->next;
	cur->next = newnode;

	return head;
}

node* leftShiftLL(node* head, int k) {
	if (head == NULL) return NULL;
	int n = lengthOfLL(head);
	k = ((k % n) + n) % n;
	if (k == 0) return head;

	node* cur = head;
	k--;
	while (k--) {
		cur = cur->next;
	}
	// cur has reached the kth node
	// make kth node as new tail
	node *newhead = cur->next;
	cur->next = NULL;

	cur = newhead;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = head;

	return newhead;
}

node* rightShiftLL(node* head, int k) {
	return leftShiftLL(head, lengthOfLL(head) - k);
}

node* deleteHead(node* head) {
	if (head == NULL) return NULL;
	node* newhead = head->next;
	delete head;
	return newhead;
}

node* deleteTail(node* head) {
	if (head == NULL) return head;
	if (lengthOfLL(head) == 1) return deleteHead(head);

	node* cur = head;
	// reach 2nd last node

	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	node* to_be_deleted = cur->next;
	cur->next = NULL;
	delete to_be_deleted;

	return head;
}

node* deleteAtK(node* head, int k) {
	if (head == NULL) return head;
	if (k == 1) return deleteHead(head);
	if (k >= lengthOfLL(head)) return deleteTail(head);

	k -= 2;
	node* cur = head;
	while (k--) {
		cur = cur->next;
	}

	node* to_be_deleted = cur->next;
	cur->next = cur->next->next;

	delete to_be_deleted;

	return head;
}

// reversing the linked list
// iterative reverse code
node* reverse(node* head) {
	node *cur = head, *prev = NULL;
	while (cur) {
		node* ahead = cur->next;
		cur->next = prev;
		prev = cur;
		cur = ahead;
	}
	return prev;
}

// recursively code the reverse linked list
node* reverse_recursive(node* head) {
	// tail node
	if (head->next == NULL) return head;

	node* newhead = reverse_recursive(head->next);

	// first time??
	// second last node
	head->next->next = head;
	head->next = NULL;

	return newhead;
}

node* findMidPoint(node* head) {
	if (lengthOfLL(head) <= 2) {
		return head;
	}
	node *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergeTwoSortedLinkedList(node* head1, node* head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	if (head1->data < head2->data) {
		head1->next = mergeTwoSortedLinkedList(head1->next, head2);
		return head1;
	}
	else {
		head2->next = mergeTwoSortedLinkedList(head1, head2->next);
		return head2;
	}
}

// homework {TODO}
// node* mergeTwoSortedLinkedListIterative(node* head) {

// }

node* mergeSort(node* head) {
	if (head == NULL || head->next == NULL) return head;

	node* midPoint = findMidPoint(head);

	node* firsthead = head;
	node* secondhead = midPoint->next;
	midPoint->next = NULL;

	firsthead = mergeSort(firsthead);
	secondhead = mergeSort(secondhead);

	return mergeTwoSortedLinkedList(firsthead, secondhead);
}

// O(n)
bool has_Cycle(node *head) {
	node *slow = head, *fast = head;

	while (slow && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}

	return false;
}

// O(n)
node* detectCyclicNode(node* head) {
	if (!has_Cycle(head)) return NULL;

	node *slow = head, *fast = head;
	while (1) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	// cout << "they met at " << slow->data << '\n';

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	// or return fast
	return slow;
}

// todo : break cycle


// O(n)
node* removeDuplicatesFromSortedList(node* head) {
	node* cur = head;
	while (cur && cur->next) {
		if (cur->next->data == cur->data) {
			cur->next = cur->next->next;
		}
		else {
			cur = cur->next;
		}
	}

	return head;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	node* head = construct_ll();
	printll(head);
	// head = insertAtHead(head, 6);
	// printll(head);
	// head = insertAtTail(head, 7);
	// printll(head);
	// head = insertAtK(head, 3, 10);
	// printll(head);
	// head = leftShiftLL(head, -3);
	// head = deleteHead(head);
	// head = deleteTail(head);
	// head = deleteAtK(head, 4);
	// head = reverse_recursive(head);
	// node* midPoint = findMidPoint(head);
	// cout << midPoint->data << '\n';
	// head = mergeSort(head);

	// make a cycle the list
	// head->next->next->next->next->next->next->next = head->next->next;
	// bool is_cycle = has_Cycle(head);
	// cout << is_cycle;

	// node* cyclicNode = detectCyclicNode(head);
	// cout << cyclicNode->data;

	head = removeDuplicatesFromSortedList(head);
	printll(head);

	return 0;
}