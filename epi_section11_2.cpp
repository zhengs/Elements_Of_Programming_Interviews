#include <iostream>
#include <vector>
using namespace std;


int firstLargerThan(vector<int> * v, int a) {
	int left = 0;
	int right = v->size()-1;
	int i = left + (right - left)/2;
	bool found = false;
	int prev_i = i;
	int smallest_i;
	while(true) {
		if(found == false) {
			if((*v)[i] <= a) {
				left = i + 1;
				i = left + (right - left)/2;
				if(i == prev_i)
					return -1;
			} else {
				found = true;
				smallest_i = i;
				right = i - 1;
				i = left + (right - left)/2;
				if(i == prev_i)
					return smallest_i;
			}
		} else {
			if((*v)[i] <= a) {
				left = i + 1;
				i = left + (right - left)/2;
				if(i == prev_i)
					return smallest_i;
			} else {
				smallest_i = i;
				right = i - 1;
				i = left + (right - left)/2;
				if(i == prev_i)
					return smallest_i;
			}
		}
		prev_i = i;
	}
	return -1;
}

int main() {
	srand (time(NULL));
	vector<int> v(10);
	cout << "v: ";
	for(int i = 0; i < v.size(); i++) {
		v[i] = rand() % 20;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	cout << firstLargerThan(&v, 10) << endl;
}