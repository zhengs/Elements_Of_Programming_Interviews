#include <iostream>
#include <assert.h>
using namespace std;


unsigned int reverse(unsigned int l) {
	unsigned int r = 0;
	for(int i = 0; i < sizeof(l) * 8; i++ ) {
		int a = l & 0x1;
		r+= a << (sizeof(l)*8-i-1);
		l >>= 1;
	}
	return r;
}

int main() {
	printf("%x\n", reverse(15));

	return 1;
}