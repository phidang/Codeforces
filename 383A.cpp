#include <bits/stdc++.h>

using namespace std; 

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, a[200010], b[200010];

int main() {
	if (debug) openfile;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	long long res=0;
	b[0]=0;
	if (a[0]==1) b[0]=1;
	for (int i=1; i<n; i++) {
		if (a[i]==1) {
			b[i]=b[i-1]+1;
		}
		else {
			b[i]=b[i-1];
			res+=b[i];
		}
	}
	cout<<res<<endl;
	return 0;
}