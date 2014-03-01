#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

pair<int, int> increase(vector<int> &vi) {
	vector<pair<int, int> > record(vi.size(), pair<int, int>());
	int maxLen = INT_MIN;
	int maxBegin = 0;
	int maxEnd = 0;
	for(int i = 0; i < vi.size();i++) {
		int n = vi[i];
		int len = 1;
		int begin = i;
		for(int j = 0; j < i; j++) {
			if(n > vi[j]) {
				if(len < record[j].first + 1) {
					len = record[j].first + 1;
					begin = record[j].second;
				}
			}
		}
		record[i] = pair<int, int>(len, begin);
		if(len > maxLen) {
			maxLen = len;
			maxBegin = begin;
			maxEnd = i;
		}
	}
	return pair<int, int>(maxBegin, maxEnd);
}

int main() {
	int a[] = {6, 1, 1, 9, 4, 5, 2, 3, 4, 5, 6};
	vector<int> vi(sizeof(a)/sizeof(a[0]));
	copy(a, a+sizeof(a)/sizeof(a[0]), vi.begin());
	pair<int, int> p = increase(vi);
	cout << p.first << " " << p.second << endl;
	return 1;
}