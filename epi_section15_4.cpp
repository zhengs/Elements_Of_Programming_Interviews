#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Node{
public:
	int val;
	vector<Node*> children;
public:
	Node(int x): val(x), children((vector<Node*>)0) {}
};

/* time complexity = O(n), space complexity = O(h), where
h is the max height of the tree
*/
pair<int,int> dia(Node* head) {
	if(head->children.empty() == true)
		return pair<int,int>(head->val, 0);
	vector<int> childrenLen;
	for(std::vector<Node*>::iterator it = head->children.begin();
		it != head->children.end(); it++) {
		Node* n = *it;
	childrenLen.push_back(dia(n).first);
	}
	sort(childrenLen.begin(), childrenLen.end());
	pair<int,int> r;
	r.first = childrenLen[0];
	if(childrenLen.size() > 1)
		r.second = childrenLen[1];
	else
		r.second = 0;
	return r;
}

int main() {
	// arbitrary tests below
	srand (time(NULL));
	vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(rand()%30);
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < 10; i++)
		cout<<v[i] << " ";
	cout << endl;

	set<int, greater<int> > s;
	for(int i = 0; i < 10; i++)
		s.insert(rand()%20);

	for(set<int>::iterator it = s.begin(); 
		it != s.end(); it++)
		cout<< *it << " ";
	cout << endl;

}