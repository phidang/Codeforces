#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int k[4];

int main() {
	if (debug) openfile;
	for (int i=0; i<4; i++) {
		cin>>k[i];
	}
	int res = min(k[0],min(k[2],k[3]));
	k[0]-=res;
	res = res*256 + min(k[0],k[1])*32;
	cout<<res<<endl;

	return 0;
}