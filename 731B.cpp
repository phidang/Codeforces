#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, x, rem;

int main() {
	if (debug) openfile;
	cin>>n;
	rem = 0;
	for (int i=0; i<n; i++) {
		cin>>x;
		x-=rem;
		if (x<0) {
			puts("NO");
			return 0;
		} 
		if (x%2) rem=1;
		else rem=0;
	}
	if (rem>0) puts("NO");
	else puts("YES");
	return 0;
}