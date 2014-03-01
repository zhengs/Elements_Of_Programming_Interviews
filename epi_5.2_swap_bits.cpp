#include <iostream>
#include <assert.h>
using namespace std;


long swap(long l, int i, int j) {
	assert(i>=0 && i < sizeof(long)*8);
	assert(j>=0 && j < sizeof(long)*8);
	long a = l & (1 << i) >> i << j;
	long b = l & (1 << j) >> j << i;

	return (l & ~(1 << i) & ~(1<<j)) | a | b;

}