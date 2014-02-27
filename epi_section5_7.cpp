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

string convertBase(int b1, int b2, string s) {
	int sum = 0;
	int base = 1;
	for(int i = s.size()-1; i >= 0; i-- ) {
		char c = s[i];
		if(c <= '9' && c >= '0')
			sum += (c-'0')*base;
		else if(c >= 'A' && c <= 'F')
			sum += (c-'A' + 10) * base;
		else if(c >= 'a' && c <= 'f')
			sum += (c-'a' + 10) * base;
		base *= b1;
	}
	string r = "";
	while(sum > 0) {
		int res = sum%b2;
		if(res < 10)
			r += res + '0';
		else
			r += res - 10 + 'A';
		sum = sum - sum%b2;
		sum = sum/b2;
	}
	return r;
}

int main() {
	cout << convertBase(10, 16, "12");
}