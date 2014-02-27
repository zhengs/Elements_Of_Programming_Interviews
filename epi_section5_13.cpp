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


unsigned int add(unsigned int a, unsigned int b) {
	unsigned int sum = a ^ b;
	unsigned int carrying = a & b;
	while(carrying != 0) {
		carrying <<= 1;
		unsigned int tmp = sum ^ carrying;
		carrying = sum & carrying;
		sum = tmp;
	}
	return sum;
}

unsigned int mul(unsigned int a, unsigned int b) {
	unsigned long sum = 0;
	int i = 0;
	do{
		if((b & (1<<i)) != 0) {
			sum = add(sum, a<<i);
		}
		i = add(i, 1);
	} while(i < sizeof(unsigned int) * 8);

	if(sum > (((unsigned long)1)<<(sizeof(unsigned int)*8))-1)
		sum = (((unsigned long)1)<<(sizeof(unsigned int)*8))-1;
	return (unsigned int) sum;
}

int main() {
	cout << mul(112392, 11) << endl;

}