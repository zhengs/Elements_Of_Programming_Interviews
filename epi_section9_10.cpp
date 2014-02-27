#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

class Node{
public:
	int val;
	int size;
	Node *left, *right;
};

void formLinkedList(Node* root, list<int>* L) {
	if(root == NULL)
		return;
	if(L == NULL) {
		L = new list<int>();
	}
	if(root->left == NULL && root->right == NULL)
		L->push_back(root->val);
	else {
		formLinkedList(root->left, L);
		formLinkedList(root->right, L);
	}
}

int main() {
	/* imaging we have a linkedlist starting with head */
	int i = 0;
	traverse(head, &i);
}