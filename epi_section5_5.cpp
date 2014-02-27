#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> getSubset(string s, int len){
	vector<string> r;
	if(len == 0) {
		r.push_back("");
		return r;
	}
	
	for(int i = 0; i < s.size(); i++) {
		vector<string> tmp = getSubset(s.substr(i+1), len-1);
		for(vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
			r.push_back(s[i] + *it);
	}
	return r;
}

void subset(string s) {
	for(int i = 1; i <= s.size(); i++) {
		vector<string> sub = getSubset(s, i);
		for(vector<string>::iterator it = sub.begin(); it != sub.end(); it++)
			cout << *it << endl;
	}
}

int main() {
	subset("abcd");
	return 0;
}