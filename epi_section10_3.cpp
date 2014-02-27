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

namespace haha {
template<class T>
class less{
public:
	bool operator() (pair<int, T> &p1, pair<int, T> &p2){
		return p1.first < p2.first;
	}
};

template<class T>
class greater{
public:
	bool operator() (pair<int, T> &p1, pair<int, T> &p2){
		return p1.first > p2.first;
	}
};
}

template<class T>
class stackUsingHeap{

int order;
priority_queue<pair<int, T>, vector<pair<int, T> >, haha::less<T> > pq;

public:
	stackUsingHeap():order(0) {}
	T peek(){
		return pq.top().second;
	}
	void push(T &t){
		pq.push(pair<int, T>(order, t));
		order++;
	}
	void pop(){
		pq.pop();
	}
};

template<class T>
class queueUsingHeap{

int order;
priority_queue<pair<int, T>, vector<pair<int, T> >, haha::greater<T> > pq;

public:
	queueUsingHeap():order(0) {}
	T peek(){
		return pq.top().second;
	}
	void push(T &t){
		pq.push(pair<int, T>(order, t));
		order++;
	}
	void pop(){
		pq.pop();
	}
};


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