#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 5e4;

struct cmp{
	bool operator()(int a, int b) {
		return a>b;
	}
};

int n, a[MAX_N];
set<int, cmp> mySet, res;
vector<int> vec;

void input() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
}

void init() {
	res.clear();
	mySet.clear();
	for (int i=0; i<n; i++) {
		mySet.insert(a[i]);
	}
}

void solve() {
	init();
	for (set<int>::iterator it=mySet.begin(); it!=mySet.end(); it++) {
		int x = *it;
		vec.clear();
		while (x>0) {
			vec.push_back(x);
			x/=2;
		}
		x = -1;
		for (int i=0; i<vec.size(); i++) {
			if (mySet.find(vec[i])==mySet.end()) {
				x = vec[i];
				break;
			}
		}
		if (x==-1) {
			break;
		}
		mySet.insert(x);
	}
	for (set<int>::iterator it=mySet.find(vec[0]); it!=mySet.end(); it++) {
		cout<<*it<<' ';
	}
}


int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}