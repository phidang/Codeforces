#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

const int MAX_N=2e5+7;

int n, a[MAX_N], b[MAX_N], pos[MAX_N];

void solve() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		pos[a[i]] = i;
	}
	for (int i=0; i<n; i++) {
		cin>>b[i];
	}
	int top=0;
	for (int i=0; i<n; i++) {
		if (pos[b[i]]<top) {
			cout<<0<<' ';
		}
		else {
			cout<<pos[b[i]]-top+1<<' ';
			top = pos[b[i]]+1;
		}
	}
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}