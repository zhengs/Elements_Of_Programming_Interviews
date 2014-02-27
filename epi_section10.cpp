#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class heapHelper{
public:
	int static findLevel(int i) {
		int base = 2; 
		int lvl = 0;
		while(true) {
			if(base - 2 >= i)
				return lvl;
			else {
				base *= 2;
				lvl++;
			}
		}
	}
	int static findLeft(int i) {
		return 2 * i + 1;
	}
	int static findParent(int i) {
		return (i-1)/2;
	}
	int static findRight(int i) {
		return 2 * i + 2;
	}
	int static findLastParent(int len) {
		return (len-2)/2;
	}
};


class heap {
private:
	vector<int> v;
public:
	int len() {
		return v.size();
	}
	void show() {
		cout << "heap content = ";
		for(int i = 0; i < this->len(); i++ ) 
			cout << this->v[i] << " ";
		cout << endl;
	}
	heap(vector<int> v) {
		this->v = v;
		buildup();
	}

	void insert(int m) {
		this->v.push_back(m);
		filterUp(v.size()-1);
	}
	int remove() {
		int r = v[0];
		v[0] = v[v.size() -1];
		v.pop_back();
		filterDown(0);
		return r;
	}

	void sort() {
		cout << "sorting... ";
		while(this->len() > 0)
			cout << remove() << " ";
		cout << endl;
	}
	void filterUp(int i) {
		int i_parent = heapHelper::findParent(i);
		if(i_parent >= 0 && v[i_parent] > v[i]) {
			swap(i_parent, i);
			filterUp(i_parent);
		}
	}
	void swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	void filterDown(int i) {
		int i_left = heapHelper::findLeft(i);
		int i_right = heapHelper::findRight(i);
		if(i_left < this->len() && v[i] > v[i_left]){
			if(i_right < this->len() && v[i_left] > v[i_right]) {
				swap(v[i], v[i_right]);
				filterDown(i_right);
			} else {
				swap(v[i], v[i_left]);
				filterDown(i_left);
			}
		}
		else if(i_right < this->len() && v[i] > v[i_right]) {
			swap(v[i], v[i_right]);
			filterDown(i_right);
		}
	}
	void buildup(){
		int i_LastParent = heapHelper::findLastParent(this->len());
		if(i_LastParent >= this->len()) return;
		for(int i = i_LastParent; i >= 0; i--) {
			cout << "buildup: " << i << endl;
			filterDown(i);
		}
	}
};

int main() {
	srand (time(NULL));
	vector<int> v;
	for(int i = 0; i < 40; i++) {
		int tmp = rand() % 30;
		// int tmp = 5-i;
		cout << tmp << " ";
		v.push_back(tmp);
	}
	cout << endl;
	heap h(v);
	h.show();
	h.sort();
	heapHelper::findLevel(3);

	priority_queue<int> pq;
	for(int i = 0; i < 10; i++) {
		int tmp = rand() % 30;
		// int tmp = 5-i;
		cout << tmp << " ";
		pq.push(tmp);
	}
	cout << endl;
	for(int i = 0; i < 10; i++) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}