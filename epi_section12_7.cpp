#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
using namespace std;



vector<pair<string, string> > anagrams(vector<string> &dict) {
	vector<pair<string, string> > r;
	map<string, vector<string> > m;
	for(int i = 0; i < dict.size(); i++) {
		string s = dict[i];
		sort(s.begin(), s.end());
		if(m.find(s) == m.end()) {
			vector<string> vs;
			vs.push_back(dict[i]);
			m[s] = vs;
		} else {
			vector<string> vs = m[s];
			vs.push_back(dict[i]);
			m[s] = vs;
		}
	}
	for(map<string, vector<string> >::iterator it = m.begin(); 
		it != m.end(); it++) {
		vector<string> vs = it->second;
		for(int i = 0; i < vs.size(); i++)
			for(int j = i+1; j < vs.size(); j++) {
				r.push_back(pair<string, string>(vs[i], vs[j]));
			}
	}
	return r;
}

int main() {}