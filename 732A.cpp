#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int k, r;

int main() {
	if (debug) openfile;
	cin>>k>>r;
	for (int i=1; i<=10; i++) {
		if ((k*i-r)%10==0 || k*i%10==0) {
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}