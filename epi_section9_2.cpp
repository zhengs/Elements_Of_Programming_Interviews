


#include <iostream>
using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	int value;
};

Node* kb(Node* head) {
	if(head == NULL) return NULL;
	return kb_helper(head);
}

Node* kb_helper(Node* head, bool* r) {
	
}