#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, pos;

int main() {
	if (debug) openfile;
	cin>>n;
	pos = 0;
	for (int i=0; i<n; i++) {
		int x;
		string s;
		cin>>x>>s;
		if ((pos==0 && s!="South") || (pos==20000 && s!="North")) {
			puts("NO");
			return 0;
		}
		if (s=="North") {
			if (pos>0) pos-=x;
		}
		else if (s=="South") {
			if (pos<20000) pos+=x;
		}
		if (pos<0 || pos>20000) {
			puts("NO");
			return 0;
		}
	}
	if (pos==0) {
		puts("YES");
	}
	else puts("NO");
	return 0;
}