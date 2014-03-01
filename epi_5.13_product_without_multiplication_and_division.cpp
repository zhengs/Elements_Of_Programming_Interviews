#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

unsigned int prod(unsigned int a, unsigned int b) {
	unsigned int sum = 0;
	for(unsigned int i = 0; i < b; i++) {
		bool carry = false;
		for(int j = 0; j < sizeof(a)*8; j++) {
			if(carry == true) {
				carry = ((sum >> j) & 0x1) || ((a>>j) & 0x1);
				sum = sum ^ (1 << j);
				sum = sum ^ (((a >> j) & 0x1) << j);
			} else {
				carry = ((sum >> j) & 0x1) && ((a>>j) & 0x1);
				sum = sum ^ (((a >> j) & 0x1) << j);
			}
		}
		// cout << sum << endl;
	}
	return sum;
}

int main() {
	cout << prod(321,120) << endl;
	return 1;
}