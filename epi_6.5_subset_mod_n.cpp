#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

vector<int> subset_mod_n(vector<int> &vi) {
	int n = vi.size();
	vector<int> sum_mod(vi.size(), 0);
	int sum = 0;
	unordered_map<int, int> m;
	for(int i = 0; i < vi.size(); i++) {
		sum += vi[i];
		sum_mod[i] = sum%n;
		if(sum_mod[i] == 0) {
			vector<int> r;
			for(int j = 0; j <= i; j++) {
				r.push_back(vi[j]);
			}
			return r;
		}
		if(m.find(sum_mod[i]) != m.end()) {
			vector<int> r;
			for(int j = m[sum_mod[i]]+1; j <= i; j++) {
				r.push_back(vi[j]);
			}
			return r;
		} else {
			m[sum_mod[i]] = i;
		}
	}
}

int main() {
	int a[] = {6, 1, 1, 9, 4, 5};
	vector<int> vi(sizeof(a)/sizeof(a[0]));
	copy(a, a+sizeof(a)/sizeof(a[0]), vi.begin());
	vector<int> r = subset_mod_n(vi);
	for_each(r.begin(), r.end(), [](int i){cout << i << " ";});
	return 1;
}