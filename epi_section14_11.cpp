#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
using namespace std;

class Node{
public:
	int val;
	Node *left, *right;
public:
	Node(int x): val(x), left((Node*)0), right((Node*)0) {}
};

void buildTree(Node **head, vector<int> pre, vector<int> in, int len) {
	if(len <= 0) return;
	int cur = pre[0];
	vector<int>::iterator pos = find(in.begin(), in.end(), cur);
	len = pos - in.begin();
	vector<int> v1(&pre[1], &pre[1+len - 1]);
	vector<int> v2(in.begin(), pos-1);
	vector<int> v3(&pre[1+len], &pre[pre.size()-1]);
	vector<int> v4(pos+1, in.end()-1);
	buildTree(&((*head)->left), v1, v2, len);
	buildTree(&((*head)->right), v3, v4, len);
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << &v << endl;
	cout << *v.begin() << endl;
	vector<int> v2(&v[0], &v[3]);
	for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		cout << *it << " " ;
	cout << endl;

	vector<int> v3(v.begin(), v.end()-1);
	for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
		cout << *it << " " ;
	cout << endl;

}