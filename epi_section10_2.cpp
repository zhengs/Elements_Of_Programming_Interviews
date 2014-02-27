#include <queue>
#include <vector>
using namespace std;

void k_increasing_decreasing(int a[], int b[], int len) {
	if(len == 0) return;
	vector<priority_queue<int, vector<int>, greater<int> > > vq;
	int i = 0;
	while(i<len) {
		priority_queue<int, vector<int>, greater<int> > *pq = 
			new priority_queue<int, vector<int>, greater<int> >();
		while(i+1 < len && a[i]<a[i+1]) {
			pq->push(a[i]);
			i++;
		}
		vq.push_back(*pq);
		pq = new priority_queue<int, vector<int>, greater<int> >();
		while(i+1 < len && a[i]>a[i+1]) {
			pq->push(a[i]);
		}
		vq.push_back(*pq);
	}
	i = 0;
	while(i < len) {
		int min = vq[0].top();
		int min_qi = 0;
		for(int j = 1; j < vq.size(); j++){
			if(vq[j].empty() == false && min > vq[j].top()) {
				min = vq[j].top();
				min_qi = j;
			}
		}
		b[i] = min;
		vq[min_qi].pop();
		i++;
	}
}

int main() {
}