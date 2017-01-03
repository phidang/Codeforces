#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, k;

int main() {
	if (debug) openfile;
	cin>>n>>k;
	int i=1;
	while (k+i*5<=240 && i<=n) {
		k+=i*5;
		i++;
	}
	cout<<i-1<<endl;
	return 0;
}