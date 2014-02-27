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
	Node* left, *right;
};

Node* findFirstNode_InOrder_recursive(Node* root, int k) {
	Node *r;
	if(root == NULL) return NULL;
	r = findFirstNode_InOrder_recursive(root->left, k);
	if(r != NULL) 
		return r;
	if(root->val == k)
		return root;
	r = findFirstNode_InOrder_recursive(root->right, k);
	if(r != NULL)
		return r;
	return NULL;
}

Node* findFirstNode_InOrder_iterative(Node* root, int k) {
	if(root == NULL) return NULL;
	stack<Node*> q;
	q.push(root);
	Node *cur = root->left;
	while(true) {
		if(cur != NULL) {
			q.push(cur);
			cur = cur->left;
		} else {
			cur = q.top();
			q.pop();
			if(cur->val == k)
				return cur;
			else
				cur = cur->right;
		}
		if(q.empty() == true)
			return NULL;
	}
}

Node* findFirstNode_PreOrder_iterative(Node* root, int k) {
	if(root == NULL) return NULL;
	if(root->val == k) return root;
	stack<Node*> q;
	q.push(root);
	Node *cur = root->left;
	while(true) {
		if(cur != NULL) {
			if(cur->val == k) 
				return cur;
			q.push(cur);
			cur = cur->left;
		} else {
			cur = q.top();
			q.pop();
			cur = cur->right;
		}
		if(q.empty() == true)
			return NULL;
	}
}

// in the case of post ordering, you'd need an additional field
// to differentiate between a first visit of a node and a second visit
Node* findFirstNode_PostOrder_iterative(Node* root, int k) {
	if(root == NULL) return NULL;
	stack<pair<Node*, bool> > q;
	q.push(root, true);
	Node *cur = root->left;
	while(true) {
		if(cur != NULL) {
			q.push(cur, true);
			cur = cur->left;
		} else {
			cur = q.top().first;
			bool first = q.top().second;
			q.pop();
			if(first == true) {
				q.push(cur, false);
				cur = cur->right;
			} else {
				if(cur->val == k)
					return cur;
				cur = NULL;
			}
		}
		if(q.empty() == true)
			return NULL;
	}
}
int main() {

}