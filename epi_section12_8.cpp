#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool canBePalindrome_1(string s) {
	// time complexity: O(n)
	// space complexity: O(k)
	unordered_map<char, int> m;
	for(int i = 0; i < s.size(); i++){
		if(m.find(s[i]) == m.end()) {
			m[s[i]] = 1;
		} else
			m[s[i]]++;
	}
	int single = 0;
	for(unordered_map<char, int>::iterator it = m.begin(); it!=m.end(); it++){
		if(it->second%2 != 0) {
			single++;
			if(single > 1)
				return false;
		}
	}
	return true;
}

bool canBePalindrome_2(string s) {
	// time complexity: O(nlogn)
	// space complexity: O(1)
	if(s.size() <= 1) return true;
	sort(s.begin(), s.end());
	cout << s << endl;
	int i = 0;
	int single = 0;
	while(i < s.size()) {
		int count = 1;
		while(i < s.size() && s[i] == s[i+1]) {
			count++;
			i++;
		}
		if(count%2 == 1)
			single++;
		if(single > 1) 
			return false;
		i++;
	}
	return true;
}

int main() {
	cout << canBePalindrome_2("haahha") << endl;
}