#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>* h, int a, int b) {
	int tmp = h->at(a);
	h->at(a) = h->at(b);
	h->at(b) = tmp;
}

vector<int>* sort(vector<int>* h, int i) {
	if(i > h->size()) return 0;
	int n_le = 0;
	int n_eq = 0;

	vector<int>::iterator it = h->begin();
	while(it != h->end()) {
		if(*it < h->at(i))
			n_le++;
		else if(*it == h->at(i)) 
			n_eq++;
		it++;
	}
	// cout << "haha " << h->at(i) << " " << n_le << " " << n_eq << endl;
	if(i != n_le)
		swap(h, i, n_le);
	for(int ii = 0; ii < n_eq; ii++)
		h->at(n_le + ii) = h->at(n_le);
	int i_back = n_le - 1;
	int i_forward = n_le + n_eq;
	// cout << "haha " << i_back << " " << i_forward << endl;
	while(i_back >= 0 && i_forward < h->size()) {
		while(i_back >= 0 && h->at(i_back) < h->at(n_le)) {
			// cout << "lalal " << h->at(i_back) << " " << h->at(n_le) << " " << i_back << endl;
			i_back--;
		}
		// cout << "haha " << i_back << " " << i_forward << endl;
		if(i_back < 0) break;
		while(i_forward < h->size() && h->at(i_forward) > h->at(n_le)) {
			// cout << "lelele " << h->at(i_forward) << " " << h->at(n_le) << " " << i_forward << endl;
			i_forward++;
		}
		// cout << "haha " << i_back << " " << i_forward << endl;
		if(i_forward >= h->size()) break;
		swap(h, i_back, i_forward);
		// cout << "hehe " << i_back << " " << i_forward << endl;
	}
	return h;
}

void show(vector<int>* h) {
	for(vector<int>::iterator it = h->begin(); it != h->end(); it++)
		cout << *it << " ";
	cout << endl;

}
int main() {
	/* initialize random seed: */
	srand (time(NULL));

	vector<int>* h = new vector<int>();
	int len = 10;
	int pos = 9;
	for(int i = 0; i < len; i++)
		h->push_back(rand() % 100);
	show(h);
	cout << h->at(pos) << endl;
	h = sort(h, pos);
	show(h);
	return 0;
}