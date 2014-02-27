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

class compareLess{
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	}
};

class compareGreater{
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	}
};

vector<int>& returnVector(vector<int> &a, vector<int> &b, vector<int> &c, int i) {
	if(i == 0)
		return a;
	else if(i == 1) 
		return b;
	else if(i == 2)
		return c;
}

pair<int, int> findMax(int a, int b, int c) {
	if(a > b) {
		if(a > c)
			return pair<int,int>(a, 0);
		else 
			return pair<int,int>(c, 2);
	} else {
		if(b > c)
			return pair<int,int>(b, 1);
		else
			return pair<int,int>(c, 2);
	}
}

pair<int,int> findMin(int a, int b, int c) {
	if(a < b) {
		if(a < c)
			return pair<int,int>(a, 0);
		else 
			return pair<int,int>(c, 2);
	}
	else {
		if(b < c)
			return pair<int,int>(b, 1);
		else
			return pair<int,int>(c, 2);
	}
}
pair<int, int*> findMinDistance(vector<int> a, vector<int> b, vector<int> c) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int idx[3] = {0, 0, 0};
	int dist = 100000;
	int *distv = new int[3];
	int i = 30;
	while(true){
		pair<int, int> pmin = findMin(a[idx[0]], b[idx[1]], c[idx[2]]);
		pair<int, int> pmax = findMax(a[idx[0]], b[idx[1]], c[idx[2]]);
		cout << "pmin: " << pmin.first << " " << pmin.second;
		cout << "; pmax: " << pmax.first << " " << pmax.second;
		cout << "; " << a[idx[0]] << ", " << b[idx[1]] << ", " << c[idx[2]];
		
		if(pmax.first - pmin.first < dist) {
			dist = pmax.first - pmin.first;
			distv[0] = a[idx[0]];
			distv[1] = b[idx[1]];
			distv[2] = c[idx[2]];
		}
		cout << "; dist = " << dist << endl;
		if(idx[pmin.second] + 1 < returnVector(a, b, c, pmin.second).size()) {
			idx[pmin.second]++;
		} else 
			break;
	}
	return pair<int, int*>(dist, distv);
}


int main() {
	srand (time(NULL));
	// int myints1[] = {1,2,3,4};
	// vector<int> a(myints1, myints1 + sizeof(myints1) / sizeof(int));
	
	// int myints2[] = {0,5,6,7};
	// vector<int> b(myints2, myints2 + sizeof(myints2) / sizeof(int));
	
	// int myints3[] = {8,9,3,10};
	// vector<int> c(myints3, myints3 + sizeof(myints3) / sizeof(int));
	int len = 300;
	int range = 100000;
	vector<int> a(len, 0);
	for(int i = 0; i < len; i++)
		a[i] = rand() % range;

	vector<int> b(len, 0);
	for(int i = 0; i < len; i++)
		b[i] = rand() % range;

	vector<int> c(len, 0);
	for(int i = 0; i < len; i++)
		c[i] = rand() % range;

	pair<int, int*> p = findMinDistance(a, b, c);
	cout << p.first << ": " << p.second[0] << ", " << p.second[1] << ", " << p.second[2] << endl;

	// brute force
	int min = 10000;
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size();j++)
			for(int k = 0; k < c.size(); k++)
				if(min > findMax(a[i], b[j], c[k]).first - findMin(a[i], b[j], c[k]).first)
					min = findMax(a[i], b[j], c[k]).first - findMin(a[i], b[j], c[k]).first;
	cout << "brute-force: " << min;
}