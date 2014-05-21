#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

vector<int> next_perm(vector<int> &vi) {
	int i = vi.size()-2;
	while(i >= 0){
		if(vi[i] < vi[i+1]) {
			break;
		}
		i--;
	}
	if(i == -1) {
		return vector<int>();
	}
	vector<int> r(vi);
	sort(r.begin() + i+1, r.end());
	swap(r[i], r[i+1]);
	sort(r.begin() + i+1, r.end());
	return r;
}

int main() {
	int a[] = {5, 4, 2, 1, 0};
	vector<int> vi(sizeof(a)/sizeof(a[0]), 0);
	copy(a,a+sizeof(a)/sizeof(a[0]), vi.begin());
	vector<int> r = next_perm(vi);
	for_each(r.begin(), r.end(), [](int i) {cout << i << " ";});
	return 1;
}