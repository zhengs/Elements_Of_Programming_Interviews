#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

int maxGas(vector<int> vi) {
	int min = vi[0];
	int max = 0;
	for(int i = 0; i < vi.size(); i++) {
		if(vi[i]< min) {
			min = vi[i];
		}
		if(vi[i] - min > max) {
			max = vi[i] - min;
		}
	}
	return max;
}

int main() {
	int a[] = {3, 1, 2, 9, 4, 5};
	vector<int> vi(sizeof(a)/sizeof(a[0]));
	copy(a, a+sizeof(a)/sizeof(a[0]), vi.begin());
	cout << maxGas(vi) << endl;
	return 1;
}