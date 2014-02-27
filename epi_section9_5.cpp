#include <iostream>
#include <vector>
#include <list>

using namespace std;


class node
{
public:
	int a;
	node* left;
	node* right;
public:
	node(int a) {
		this->a = a;
		this->left = 0;
		this->right = 0;
	};
	~node();

	/* data */
};

void traverse(node* root) {
	node* cur = root;
	bool firstVisit = true;
	bool backFromLeft = true;
	while(true) {
		if(firstVisit == true) {
			if(cur->left != 0) {
				cur = cur->left;
				backFromLeft = true;
				firstVisit = true;
			} else {
				cout << cur-> a;
				if(cur->right != 0) {
					cur = cur->right;
					backFromLeft = false;
					firstVisit = true;
				} else {
					cur = cur->parent;
					firstVisit = false;
				}
			}
		} else {
			if(cur == 0 || cur == r)
				break;
			else {
				if(backFromLeft == true) {
					cout << cur->a;
					if(cur->right != 0) {
						cur = cur->right;
						backFromLeft = false;
						firstVisit = true;
					} else {
						cur = cur->parent;
						firstVisit = false;
					}
				} else {
					cur = cur->parent;
					firstVisit = false;
				}
			}
		}
	}
}

int main() {
	srand (time(NULL));
	node* r = new node(3);
	node** p = &(r);
	for(int i = 0; i < 10; i++) {
		if(rand()%2) {
			p = &((*p)->left);
		} else {
			p = &((*p)->right);
		}
		*p = new node(rand() % 10);
	}
	traverse(r);
}