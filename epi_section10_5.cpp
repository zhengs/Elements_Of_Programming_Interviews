#include <queue>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int k_largest(int *a, int len, int k) {
	priority_queue<int, vector<int>, greater<int> > pq;
	int i = 0;
	while(i < len) {
		int n = a[i];
		if(pq.size() < k)
			pq.push(n);
		else {
			if(a[i] > pq.top()) {
				pq.push(a[i]);
				pq.pop();
			}
		}
		i++;	
	}
	return pq.top();
}

int main() {
	int len = 100;
	int *a = new int[len];
	for(int i = 0; i < len; i++){
		a[i] = i;
	}
	cout << k_largest(a, len, 3) << endl;
}