

#include <vector>
#include <iostream>
using namespace std;


vector<int> doors(int num){
	vector<int> r;
	for(int i = 1; i < num; i++) {
		int flip = 0;
		for(int k = 1; k < i; k++) {
			if(i%k == 0) flip++;
		}
		if(flip%2 == 0) 
			r.push_back(i);
	}
	return r;
}

int main() {
	vector<int> r = doors(500);
	vector<int>::iterator it = r.begin();
	while(it != r.end()){
		cout << *it << " ";
		it++;
	}
}