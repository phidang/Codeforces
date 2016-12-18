#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int a[4] = {6, 8, 4, 2};

int n;

void input() {
	cin>>n;
}

void solve() {
	if (n==0) {
		puts("1");
		return;
	}
	n%=4;
	cout<<a[n]<<endl;
}

int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}