#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, c;

int main() {
	if (debug) openfile;
	cin>>n>>c;
	int prev;
	cin>>prev;
	int cnt = 1;
	for (int i=1; i<n; i++) {
		int x;
		cin>>x;
		if (x-prev>c) {
			cnt = 0;
		}
		cnt++;
		prev=x;
	}
	cout<<cnt<<endl;
	return 0;
}