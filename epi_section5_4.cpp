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

bool getBit(unsigned int a, int p) {
	// cout << a << " " << p << " " << (a & (1<<p)) << endl;
	return (a & (1<<p))!=0;
}
void setBit(unsigned int &a, int p, bool b) {
	if(b) {
		a = a | (1<<p);
	} else
		a = a & (~(1<<p));
}
unsigned int closestSameWeights(unsigned int a) {
	for(int i = 1; i < sizeof(unsigned int) * 8; i++) {
		if(getBit(a, i) != getBit(a, i-1)) {
			// cout << "got it: " << i << endl;
			setBit(a, i, !(getBit(a, i)!=0));
			setBit(a, i-1, !(getBit(a, i-1)!=0));
			break;
		}
	}
	return a;
}

int main() {
	unsigned int a = 11121;
	for(int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
		cout << ((a & (unsigned int)(i<<i))!=0);
	}
	cout << endl;
	a = closestSameWeights(a);
	for(int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
		cout << ((a & (unsigned int)(i<<i))!=0);
	}
}