#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

int n, m, a[500010];

int calc(int x, int num) {
	if (num==0) {
		return a[x];
	}
	if (num%2==0) {
		a[x] = calc(x*2, num-1)^calc(x*2+1, num-1);
	}
	else {
		a[x] = calc(x*2, num-1)|calc(x*2+1, num-1);
	}
	return a[x];
}

int update(int x) {
	for (int i=0; i<n; i++) {
		if (i%2) {
			a[x] = a[x*2]^a[x*2+1];
		}
		else {
			a[x] = a[x*2]|a[x*2+1];
		}
		x/=2;
	}
	return a[1];
}

void prep() {
	cin>>n>>m;
	int nn = 1<<n;
	for (int i=nn; i<2*nn; i++) {
		cin>>a[i];
	}
	int x = calc(1, n);
	for (int i=0; i<m; i++) {
		int p, b;
		cin>>p>>b;
		a[nn+p-1]=b;
		cout<<update((nn+p-1)/2)<<endl;
	}	
}

int main() {
	if (debug) openfile;

	prep();
	return 0;
}