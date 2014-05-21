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

Node* merge(Node* h) {
	if(h == nullptr) {
		return nullptr;
	}
	if(h->next == nullptr) {
		return h;
	}
	if(h->next->next == nullptr) {
		return h;
	}
	Node *pEven, *pOdd;
	pEven = h;
	pOdd = h->next;
	while(pEven != nullptr && pOdd != nullptr) {
		pEven->next = pOdd->next;
		pEven = pEven->next;
		if(pEven == nullptr) {
			break;
		}
		pOdd->next = pEven->next;
		pOdd = pOdd->next;
	}
	pEven->next = h->next;
	return h;
}

int main() {
	return 1;
}