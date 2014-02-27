

#include <iostream>
using namespace std;
int swapBit(int a, int i, int j) {
	int vi, vj;
	int r;
	vi = (a >> i) & 0x1;
	vj = (a >> j) & 0x1;
	cout << vi << " " << vj << endl;
	r = (a & (~(1<<i))) | vj << i;
	r = (r & (~(1<<j))) | vi << j;
	return r;
}
int main() {

	int a = 4;
	int t = a;
	while(t!= 0) {
		cout << t%2;
		t/=2;
	}
	cout << endl;
	int q = swapBit(a, 2, 0);
	t = q;
	while(t!= 0) {
		cout << t%2;
		t/=2;
	}
	cout << endl;
}