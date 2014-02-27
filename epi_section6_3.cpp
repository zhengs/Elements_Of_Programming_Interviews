#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int findLargestIncrease(int seq[], int start, int end) {
	int len = end - start + 1;
	if (len == 1) return -1;
	if (len == 2) 
		return seq[end] - seq[start];
	int a1 = findLargestIncrease(seq, start, start+len/2);
	int a2 = findLargestIncrease(seq, start+len/2+1, end);
	int a3 = max(seq[start+len/2+1], seq[end]) - min(seq[start], seq[start+len/2]);
	return largestIncrease = max(max(a1,a2),a3);		
}


int robotBattery(int seq[], int len) {
	return findLargestIncrease(seq, 0, len);
}

int main() {
	cout << ssDecodeColID("B");
}