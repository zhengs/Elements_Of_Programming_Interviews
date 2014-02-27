#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
#include <queue>
#include <utility>
#include <list>
using namespace std;


class Node {
public:
	int val;
	Node* next;
};

int median(Node* enter) {
	if(enter->next == NULL)
		return enter->val;
	
	Node* cur = enter->next;
	while(true) {
		if(cur->val <= cur->next->val && cur != enter)
			cur = cur->next;
		else break;
	}
	if(cur == enter) // we have reached the beginning again
		return cur->val;

	Node* head = cur;
	int count = 0;
	while(cur->next != head) {
		cur = cur->next;
		count++;
	}
	int i = 0;
	cur = head;
	while(i < count/2) {
		cur = cur->next;
		i++;
	}
	if(count%2 == 0) {
		return (cur->val + cur->next)/2;
	} else {
		return cur->val;
	}
}

int main() {
	cout << mul(112392, 11) << endl;

}