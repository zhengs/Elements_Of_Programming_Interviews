#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

vector<vector<string> > splitString(string s, unordered_set<string> &dict, bool *result) {
	vector<vector<string> > r;
	if(s.size() == 0) {
		return r;
	}

	for(int i = 1; i < s.size(); i++) {
		string sub = s.substr(0, i);
		if(dict.find(sub) != dict.end()) { // found
			if(i != s.size()) {
				vector<vector<string> > r1;
				bool b = false;
				r1 = splitString(s.substr(i), dict, &b);
				if(b == true) {
					*result = true;
					for(vector<vector<string> >::iterator it = r1.begin(); it != r1.end(); it++) {
						for(vector<string>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) {
							string s = sub;
							it2->push_back(s);
						}
					}
				}
			} else {
				vector<string> vs;
				vs.push_back(sub);
				r.push_back(vs);
				return r;
			}
		}
	}
	return r;
}

int main() {
}