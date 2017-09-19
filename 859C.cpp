#include <bits/stdc++.h>

using namespace std;

int n, a[55], f[55], g[55];

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	f[n-1]=a[n-1];
	g[n-1]=0;
	for (int i=n-2; i>=0; i--) {
		if (a[i]+g[i+1]>f[i+1]) {
			f[i]=a[i]+g[i+1];
			g[i]=f[i+1];
		}
		else {
			f[i]=f[i+1];
			g[i]=a[i]+g[i+1];
		}
	}
	cout<<g[0]<<' '<<f[0]<<endl;
	return 0;
}