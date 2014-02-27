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

Node* find_k_th_inorder(Node* root, int k) {
	if (root->size < k) return NULL;
	Node* cur = root;
	int kk = k;
	while(true) {
		if(cur->left->size == kk-1)
			return cur;
		else if(cur->left->size < kk-1) {
			cur = cur->right;	
			kk = kk - left->size - 1;
		}
		else {
			cur = cur->left;
		}
	}
}

int main() {
	/* imaging we have a linkedlist starting with head */
	int i = 0;
	traverse(head, &i);
}