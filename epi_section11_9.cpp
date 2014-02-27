#include <queue>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

float square_root(float f){
	float down = 1;
	float up = f;
	int i = 0;
	float m;
	while(i++ < 1000) {
		m = down+(up-down)/2;
		if(m*m > f) {
			up = m;
		} else
			down = m;
	}
	return m;
}

int main() {
	cout << square_root(2) << endl;
}