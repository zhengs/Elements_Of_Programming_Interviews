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
using namespace std;

int findPivot(vector<int> array) {
	int left = 0;
	int right = array.size();
	int middle = left + (right - left)/2;
	while(true) {
		if(array[middle] >= array[left]) {
			left = middle;
			middle = left + (right - left)/2;
		} else if(array[middle] <= array[right]) {
			right = middle;
			middle = left + (right - left)/2;
		}
		if(left = right - 1)
			return right;
	}
}


int main() {
	srand (time(NULL));
	queueUsingHeap<int> s;
	for(int i = 0; i < 10; i++) {
		int a = rand() % 30;
		cout << a << " ";
		s.push(a);
	}
	cout << endl;
	for(int i = 0; i < 10; i++) {
		cout << s.peek() << " ";
		s.pop();
	}


}