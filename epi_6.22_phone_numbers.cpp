#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

vector<string> phone(vector<string> &dict, vector<int> nums) {
	if(nums.size() == 0) {
        vector<string> vs;
        vs.push_back("");
		return vs;
	}
	vector<string> r;
    int n = nums[0];
    string &s = dict[n];
    vector<string> temp = phone(dict, vector<int>(nums.begin()+1, nums.end()));
    for(int j = 0; j < s.size(); j++) {
        for(int k = 0; k < temp.size(); k++) {
            r.push_back(s[j] + temp[k]);
        }
    }
	return r;
}

int main() {
	int a[] = {5, 4, 2, 1, 0};
	vector<int> vi(sizeof(a)/sizeof(a[0]), 0);
	copy(a,a+sizeof(a)/sizeof(a[0]), vi.begin());
    
    
	string d[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs"};
	vector<string> dict(sizeof(d)/sizeof(d[0]));
	copy(d, d + sizeof(d)/sizeof(d[0]), dict.begin());
	vector<string> vs = phone(dict, vi);
	for_each(vs.begin(), vs.end(), [] (string s) {cout << s << endl;});
	return 1;
}