#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

string reverseString(string in) {
	string out;
	int ileft, iright;
	iright = in.size()-1;
	while(in[iright] == ' ') 
		iright--;
	ileft = iright;
	while(ileft >= 0) {
		while(in[ileft] != ' ' && ileft >= 0)
			ileft--;
		if(ileft < 0) {
			if(in[0] != ' ')
				out += in.substr(ileft+1, iright-ileft) + " ";
			break;
		}
		// now the word is (ileft, iright]
		out += in.substr(ileft+1, iright-ileft) + " ";
		while(in[ileft] == ' ' && ileft >= 0)
			ileft--;
		if(ileft < 0) 
			break;
		iright = ileft;
	}
	iright = out.size()-1;
	while(out[iright] == ' ')
		iright--;
	out = out.substr(0, iright+1);
	return out;
}

int main() {
	cout << reverseString("   i    ");
}