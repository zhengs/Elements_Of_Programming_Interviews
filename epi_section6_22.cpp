#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;


vector<string> showChars(int s[], int len, map<int, vector<char> > &m) {
	if(len == 0)
		return vector<string>(1, string(""));
	int a = s[0];
	vector<char> vc = m[a];
	vector<string> vsr;
	for(vector<char>::iterator it = vc.begin(); it != vc.end(); it++) {
		// cout << "it = " << *it << endl;
		string r = "";
		vector<string> vs = showChars(&s[1], len-1, m);
		for(vector<string>::iterator it2 = vs.begin(); it2 != vs.end(); it2++) {
			r = *it + *it2;
			vsr.push_back(r);
		}
	}
	return vsr;
}


int main() {
	map<int, vector<char> > m;
	vector<char> vc;
	m[1] = vc;
	vc.push_back('a'); vc.push_back('b'); vc.push_back('c');
	m[2] = vc;
	vc.clear();
	vc.push_back('d'); vc.push_back('e'); vc.push_back('f');
	m[3] = vc;
	int s[] = {2,3,2};
	vector<string> vs = showChars(s, sizeof(s)/sizeof(*s), m);
	for(vector<string>::iterator it = vs.begin(); it != vs.end(); it++) {
		cout << *it << endl;
	}
}