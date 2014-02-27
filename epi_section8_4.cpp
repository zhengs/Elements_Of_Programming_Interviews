#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* jump;
	int order;
	Node(int x): val(x), next((Node*)NULL), jump((Node*)NULL), order(-1){}
};

void traverseRecursive(Node* cur, int* i) {
	if(cur == NULL) return;
	cur->order = *i;
	(*i)++;
	if(cur->jump != NULL && cur->jump->order == -1)
		traverse(cur->jump, i);
	else if(cur->next != NULL && cur->next->order == -1) 
		traverse(cur->next, i);
}

void void traverseIterative(Node* cur, int* i) {
	if(cur == NULL) return;
	stack<Node*> s;
	while(true) {
		if(cur->order == -1)
			cur->order = *i;
		if(cur->jump != NULL && cur->jump->order == -1) {
			s.push(cur);
			cur = cur->jump;
		} else if(cur->next != NULL && cur->next->order == -1) {
			s.push(cur);
			cur = cur->next;
		} else {
			if(s.empty() == false) {
				cur = s.top();
				s.pop();
			} else {
				break;
			}
		}
	}
}

int main() {
	/* imaging we have a linkedlist starting with head */
	int i = 0;
	traverse(head, &i);
}