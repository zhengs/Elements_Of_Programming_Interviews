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

string prod(string s1, string s2) {
	int carry = 0;
	int pos = 0;
	string r = "";
	while(pos <= s1.size() + s2.size() - 2) {
		int sum = 0;
		for(int j = 0; j <= pos; j++)
			if(j < s2.size() && pos-j < s1.size())
				sum += (s2[s2.size()-1-j] - '0') * (s1[s1.size()-1-pos+j] - '0');
		sum += carry;
		r += sum%10 + '0';

		carry = sum/10;
		// cout << pos << " " << sum << " " << carry << endl;
		pos++;
	}
	for(int i = 0; i < r.size()/2; i++) {
		char c = r[i];
		r[i] = r[r.size()-1-i];
		r[r.size()-1-i] = c;
	} 
	return r;
}

int main() {
	cout << prod("12342123341343124312432", "3942384324241857184578141341341349934982989143141351545454413431431434141234");
}