#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

void spiralOrder(int *a, int len) {
	int xmin, ymin, xmax, ymax;
	xmin = 0; ymin = 0; xmax = len-1; ymax = len-1;
	int i = xmin, j = ymin;
	string r;
	bool finished = false;
	cout << "haha";
	while(true) {
		finished = true;
		for(int i = xmin; i <= xmax; i++){
			finished = false;
			cout << a[ymin*len + i] << " ";
		}
		ymin++;
		for(int j = ymin; j <= ymax; j++){
			finished = false;
			cout << a[j*len + xmax] << " ";
		}
		xmax--;
		for(int i = xmax; i >= xmin; i--){
			finished = false;
			cout << a[ymax*len + i] << " ";
		}
		ymax--;
		for(int j = ymax; j >= ymin; j--){
			finished = false;
			cout << a[j*len + xmin] << " ";
		}
		xmin++;
		if(finished == true)
			return;
	}
}

int main() {
	int a[100];
	cout <<"haha";
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			a[i * 10 + j] = i * 10 + j;
	spiralOrder(a, 10);
}