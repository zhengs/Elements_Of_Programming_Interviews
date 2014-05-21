#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

class Node {
public:
	int value;
	Node *next;
};

Node* merge(Node* head1, Node* head2) {
	if(head1 == nullptr || head2 == nullptr) {
		return nullptr;
	}
	Node *p = new Node();
	Node *q = p;
	while(head1 != nullptr && head2 != nullptr) {
		if(head1->value < head2->value) {
			p->next = head1;
			p = head1;
			head1 = head1->next;
		} else {
			p->next = head2;
			p = head2;
			head2 = head2->next;
		}
	}
	if(head1 == nullptr) {
		p->next = head2;
	} else {
		p->next = head1;
	}
	return q->next;
}

int main() {
	return 1;
}