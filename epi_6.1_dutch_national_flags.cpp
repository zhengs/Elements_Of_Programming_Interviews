#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void rearrange(vector<int> &vi, int i) {
	assert(i < vi.size());
	swap(vi[i], vi[vi.size()-1]);
	int iInsert = 0;
	int iNow = 0;
	while(iNow < vi.size()-1 ) {
		if(vi[iNow] < vi[vi.size()-1]) {
			swap(vi[iInsert],vi[iNow]);
			iInsert++;
			iNow++;
		} else {
			iNow++;
		}
	}
	cout << iNow << "; " << iInsert << "; " << vi[vi.size()-1] << endl;
	iNow = iInsert;	

	while(iNow < vi.size()-1) {
		if(vi[iNow] <= vi[vi.size()-1]) {
			swap(vi[iInsert], vi[iNow]);
			iInsert ++;
			iNow++;
		} else {
			iNow++;
		}
	}
	cout << iNow << "; " << iInsert << "; " << vi[vi.size()-1]  << "; " << vi[iInsert] << endl;
	swap(vi[iInsert], vi[vi.size()-1]);
	cout << iNow << "; " << iInsert << "; " << vi[vi.size()-1] << endl;
}

int main() {
	int a[] = {3, 1, 2, 9, 4, 5};
	vector<int> vi(sizeof(a)/sizeof(a[0]));
	cout << "haha" << endl;
	copy(a, a + sizeof(a)/sizeof(a[0]), vi.begin());
	cout << "haha" << endl;
	rearrange(vi, 3);
	for_each(vi.begin(), vi.end(), [](int i) {cout << i << " ";});
	return 1;
}