#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
using namespace std;

int minCoveringSet(array<string, 8> s, array<string, 8> b) {
	int i = 0;
	queue<pair<string, int> > qu;
	unordered_map<string, int> m;
	unordered_set<string> sets;
	int start = -1;
	int end = -1;
	int min = 100000;
	for(int j = 0; j < b.size(); j++) {
		m[b[j]] = -1;
	}
	for(int j = 0; j < s.size(); j++) {
		string cur = s[j];
		if(m.find(cur) == m.end())
			continue;
		qu.push(pair<string, int>(cur, j));
		if(sets.size() == 0) {
			sets.insert(cur);
			start = j;
		} else if(sets.size() == b.size()) {
			if(cur == qu.front().first) {
				qu.pop();
				start = qu.front().second;
				end = j;
				if(end - start < min)
					min = end - start;
			}
		} else if(sets.size() == b.size() -1 && sets.find(cur) == sets.end()) {
			sets.insert(cur);
			end = j;
			if(end - start < min)
				min = end - start;
		} else {
			sets.insert(cur);
		}
	}
	return min;	
}

int main() {
}