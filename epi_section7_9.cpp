

#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int x):val(x), next(NULL) {}
};

Node* reverse_singly_linked_list(Node* head) {
	Node *node, *b, *a;
	node = head;
	a = node->next->next;
	b = node->next;
	while(a != NULL) {
		b->next = node;
		node = b;
		b = a;
		a = a->next;
	}
	b->next = node;
	head->next = NULL;
	return b;
}

int main() {
}