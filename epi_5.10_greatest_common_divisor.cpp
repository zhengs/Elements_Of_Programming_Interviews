#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

bool isOdd(const int x) {
	return (x & 0x1);
}

bool isEven(const int x) {
	return !isOdd(x);
}
int GCD(const int x, const int y) {
	if(x == 1 || y == 1) {
		return 1;
	}
	if(x == y) {
		return x;
	}
	if(isEven(x) && isEven(y)) {
		return GCD(x>>1, y>>1) << 1;
	}
	if(isEven(x) && isOdd(y)) {
		return GCD(x>>1, y);
	}
	if(isOdd(x) && isEven(y)) {
		return GCD(x, y>>1);
	}
	if(isOdd(x) && isOdd(y)) {
		return GCD(max(x,y) - min(x,y), min(x,y));
	}
}

int main() {
	cout << GCD(1025, 250) << endl;
	return 1;
}