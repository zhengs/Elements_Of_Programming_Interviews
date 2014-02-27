#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

char* changeWords(char *in, int len) {
	int count_a = 0;
	int count_b = 0;
	for(int i = 0; i < len-1; i++) {
		if(in[i] == 'a')
			count_a++;
		if(in[i] == 'b')
			count_b++;
	}	
	int len_new = len - count_b + count_a;
	char* p = new char[len_new]();
	int i = len_new-1;
	int j = len-1;
	while(i>=0) {
		if(in[j] == 'a') {
			p[i] = 'd'; i--;
			p[i] = 'd'; i--;
			j--;
		} else if(in[j] == 'b') {
			j--;
		} else {
			p[i] = in[j];
			i--;
			j--;
		}
	}
	return p;
}

int main() {

}