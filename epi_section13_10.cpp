#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <map>
using namespace std;

int heightOfCalendar(vector<pair<int, int> > events) {
	map<int, bool> sorted_events; // true if it's a starting time
	for(vector<pair<int, int> >::iterator it = events.begin(); it != events.end(); it++) {
		sorted_events[(*it).first] = true;
		sorted_events[(*it).second] = false;
	}
	int height = 0;
	int max_height = 0;
	int prev_time = -1;
	for(map<int, bool>::iterator it = sorted_events.begin(); it != sorted_events.end(); it++){
		if((*it).second == true) {
			height++;
		} else
			height--;
		if(prev_time == -1)
			prev_time = (*it).first;
		else if(prev_time != (*it).first) {
			if(height > max_height)
				max_height = height;
		}
	}
	if(height > max_height)		
		max_height = height;
	return max_height;
}

int main() {

}