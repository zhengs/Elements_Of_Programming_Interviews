#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Node{
public:
	int val;
	Node *left, *right;
};
// tree with markers
int create_from_preorder_with_markers(Node **phead, const int a[], const int len, int pos) {
	if(pos >= len) return pos;
	if(a[pos] == NULL) return pos;
	*phead = new Node();
	(*phead)->val = a[pos];
	int pos2 = create_from_preorder_with_markers(&((*phead)->left), a, len, pos + 1);
	pos2 = create_from_preorder_with_markers(&((*phead)->left), a, len, pos2 + 1);
	return pos2;
}


int main() {
	Node* head;
	int a[10];
	create_from_preorder_with_markers(&head, a, sizeof(a)/sizeof(*a), 0);
}