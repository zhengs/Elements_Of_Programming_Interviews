#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int ssDecodeColID(string s) {
	int sum;
	int base = 1;
	for(int i = s.size()-1; i >=0; i--) {
		sum += ((s[i] - 'A')%26 +1) * base;
		base *= 26;
	}
	return sum;
}

int main() {
	cout << ssDecodeColID("B");
}