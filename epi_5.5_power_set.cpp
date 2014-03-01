#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

vector<string> powerSet(string s) {
	if(s.size() == 1) {
		vector<string> vsr;
		string ss;
		ss = s[0];
		vsr.push_back(ss);
		vsr.push_back("");
		return vsr;
	}
	vector<string> vs = powerSet(s.substr(1));
	vector<string> vsr;
	for(int i = 0; i < vs.size(); i++) {
		string ss = vs[i];
		ss = s[0] + ss;
		vsr.push_back(vs[i]);
		vsr.push_back(ss);
	}
	return vsr;
}

int main() {
	string s = "abcd";
	vector<string> vs = powerSet(s);
	for_each(vs.begin(), vs.end(), [](string s) {cout << s << endl;});
	return 1;
}