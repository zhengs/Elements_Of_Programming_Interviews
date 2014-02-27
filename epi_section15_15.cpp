#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
#include <queue>
#include <utility>
#include <list>
using namespace std;

int numOfCombinations_helper(vector<int> w, int s) {
	int cur = w[0];
	// cout << "cur = " << cur << "; s = " << s << "; ";
	// for(int i = 0; i < w.size(); i++)
	// 	cout << w[i] << " ";
	// cout << endl;
	if(w.size() == 1){
		if(s%cur != 0)
			return -1;
		else 
			return 1;
	}
	int n = s/cur;
	int sum = 0;
	for(int i = 0; i <= n; i++) {
		int m = numOfCombinations_helper(vector<int>(w.begin() + 1, 
			w.end()), s-i*cur);
		if(m != -1)
			sum+=m;
	}
	return sum;
}

int numOfCombinations(vector<int> w, int s) {
	sort(w.begin(), w.end(), greater<int>());
	return numOfCombinations_helper(w, s);
}
int main() {
	int a[] = {1, 2, 5, 10};
	vector<int> w(a, a + sizeof(a)/sizeof(*a));
	cout << numOfCombinations(w, 123);
}