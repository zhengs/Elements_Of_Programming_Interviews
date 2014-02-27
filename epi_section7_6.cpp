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
	Node* next;
};
void even_odd(Node* head) {
	if(head == NULL) return;
	Node *even, *odd;
	even = head;
	odd = even->next;
	Node *save_odd = odd;
	while(even != NULL && odd != NULL) {
		even->next = odd->next;
		odd->next = even->next;
		even = even->next;
		odd = odd->next;
	}
	if(even == NULL) {
		even = head;
		while(even->next != NULL)
			even=even->next;
	}
	even->next = save_odd;
}

int main() {

}