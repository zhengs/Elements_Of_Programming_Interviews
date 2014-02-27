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


void buildTree(Node** root, int *a, int start, int end) {
	if(start > end) return;
	*root = new Node();
	int pos = (start + end)/2;
	(*root)->val = a[pos];
	buildTree(&((*root)->left), a, start, pos-1);
	buildTree(&((*root)->right), a, pos+1, end);
}


int main() {
	int a[10];
	Node *root;
	Node **p = &root;
	buildTree(p, a, 0, 10);
}