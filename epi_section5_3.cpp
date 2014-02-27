#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

long long bitReversal(long long bits) {
	long long r = 0;
	for(int i = 0; i < sizeof(long long) * 8; i++) {
		int a = bits%2;
		r = r | a;
		r <<= 1;
		bits >>= 1;
	}
	return r;
}

int main() {
}