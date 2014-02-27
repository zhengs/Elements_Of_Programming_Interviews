#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
#include <queue>
#include <utility>
#include <list>
using namespace std;


string nextPerm(string perm) {
	if(perm.size() == 1) return perm;
	if(perm.size() == 2) {
		if(perm[0] - '0' > perm[1] - '0') {
			string s;
			s += perm[1];
			s += perm[0];
			return s;
		}
		else
			return "";		
	}
	bool found = false;
	int j_found;
	priority_queue<int> pq;
	for(int i = perm.size()-2; i >= 0; i--)

}

int main() {
	cout << mul(112392, 11) << endl;

}