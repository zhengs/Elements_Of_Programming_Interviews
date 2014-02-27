#include <iostream>
#include <vector>
#include <list>

using namespace std;

class node {
public:
	int a;
	node* next;
	node() {
		a = 0;
		next = 0;
	}
};

node* merge(node* h1, node* h2){
	if(h1 == 0 || h2 == 0) return 0;
	node* r;
	node* m;
	if(h1->a < h2->a) {
		m = h1;
		h1 = h1->next;
	} else {
		m = h2;
		h2 = h2->next;
	}
	r = m;
	while(h1!=0 && h2!=0) {
		if(h1->a < h2->a) {
			m->next = h1;
			h1 = h1->next;
		} else {
			m->next = h2;
			h2 = h2->next;
		}
		m = m->next;
	}
	if(h1!=0)
		m->next = h1;
	if(h2!=0)
		m->next = h2;
	return r;
}

void show(node* h) {
	while(h!=0){
		cout << h->a << " ";
		h=h->next;
	}
	cout << endl;
}
int main() {
	srand (time(NULL));
	node* h1;
	node* h2;
	node** ph1 = &h1;
	node** ph2 = &h2;
	node* ho1 = 0;
	node* ho2 = 0;

	for(int i = 0; i < 0; i++) {
		*ph1 = new node();
		if(i == 0) ho1 = h1;
		(*ph1)->a = i * 2;
		ph1 = &((*ph1)->next);
	}
	for(int i = 0; i < 1; i++) {
		(*ph2) = new node();
		if(i == 0) ho2 = h2;
		(*ph2)->a = i * 2 + 1;
		ph2 = &((*ph2)->next);
	}
	show(ho1);
	show(ho2);
	node* m = merge(ho1, ho2);
	show(m);
}