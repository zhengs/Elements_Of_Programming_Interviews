#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
	int val;
	Node *left, *right;
public:
	Node(int x):val(x), left((Node*)0), right((Node*)0){}
};
void reconstruct(vector<int> pre, vector<int> in, Node** head) {
	if(in.size() == 0 || pre.size() == 0) return;
	Node *cur = new Node(pre[0]);
	*head = cur;
	vector<int>::iterator it = find(in.begin(), in.end(), pre[0]);
	pre.erase(pre.begin());
	reconstruct(pre, vector<int>(in.begin(), it), &(cur->left));
	reconstruct(pre, vector<int>(it+1, in.end()), &(cur->right));
}

int main() {

	return 0;
}