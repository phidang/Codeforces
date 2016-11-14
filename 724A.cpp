#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const string day[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

string d1, d2;

void solve() {
	cin>>d1>>d2;
	int idx1, idx2;
	for (int i=0; i<7; i++) {
		if (d1==day[i]) idx1=i;
		if (d2==day[i]) idx2=i;
	}
	int dis = idx2-idx1;
	if (dis<0) dis+=7;
	if (dis==0 || dis==2 || dis==3) puts("YES");
	else puts("NO");
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}