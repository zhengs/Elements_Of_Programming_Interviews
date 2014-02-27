#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int k_max(int num[], int len, int k) {
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 0; i < len; i++) {
		if(q.size() < k) {
			q.push(num[i]);
		} else {
			int a = q.top();
			cout << "top is " << a << endl;
			q.pop();
			q.push(num[i]);
		}
	}
	// while(q.size() > 1)
	// 	q.pop();
	return q.top();
}

int main() {
	int num[30];
	for(int i = 0; i < sizeof(num)/sizeof(*num); i++)
		num[i] = i;
	cout << k_max(num, sizeof(num)/sizeof(*num), 3) << endl;
	return 0;
}