#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
using namespace std;

class Node{
private:
	int val;
	Node *left, *right;
public:
	Node(int x): val(x), left((Node*)0), right((Node*)0) {}
};

Node* found = (Node*) 0 ;
bool bfound = false;
bool finished = false;
void traverse(Node* root, int key) {
	if(root == (Node*)0) return;
	
	traverse(root->left, key);
	if(finished) return;
	
	if(bfound == true) {
		found = root;
		finished = true;
		return;
	}

	if(root->val == key) {
		bfound = true;
	}

	traverse(root->right, key);
}

int main() {}