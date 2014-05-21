#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

string multiply(const string &s, const char c) {
	string r = "";
	int i = s.size()-1;
	int carry = 0;
	while(i >= 0) {
		int n = s[i] - '0';
		int prod = n * (c - '0') + carry;
		carry = prod/10;
		prod = prod%10;
		r = (char)(prod + '0') + r;
		i--;
	}
	if(carry!=0) {
		r = (char)(carry + '0') + r;
	}
	return r;
}

string add(const string &s1, const string &s2) {
	int i = s1.size()-1;
	int j = s2.size()-1;
	int carry = 0;
	string r;
	while(i >= 0 && j >= 0) {
		int n;
		n = s1[i] - '0' + s2[j] - '0' + carry;
		carry = n/10;
		n = n%10;
		r = (char)(n+'0') + r;
		i--;
		j--;
	}
	while(i>=0) {
		int n;
		n = s1[i] - '0' + carry;
		carry = n/10;
		n = n%10;
		r = (char)(n+'0') + r;	
		i--;
	}
	while(j>=0) {
		int n;
		n = s2[j] - '0' + carry;
		carry = n/10;
		n = n%10;
		r = (char)(n+'0') + r;	
		j--;
	}
	return r;
}

string multiply(const string &s1, const string &s2) {
	string base = "";
	string r = "";
	for(int i = s1.size()-1; i >= 0; i--) {
		char c = s1[i];
		string s = multiply(s2, c);
		s += base;
		base += "0";
		cout << "s = " << s << endl;
		r = add(s, r);
	}
	return r;
}

int main() {
	string s1 = "12";
	string s2 = "51233414134134";
	cout << multiply(s1, s2) << endl;
	return 1;
}