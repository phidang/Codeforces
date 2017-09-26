#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll oo = 1e15;

int n;
ll f[100010][5], p, q, r, a[100010];

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>p>>q>>r;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	f[0][1]=p*a[0];
	f[0][2]=f[0][1]+q*a[0];
	f[0][3]=f[0][2]+r*a[0];	
	for (int i=1; i<n; i++) {
		f[i][1]=max(f[i-1][1], p*a[i]);
		f[i][2]=max(f[i-1][2], f[i][1]+q*a[i]);
		f[i][3]=max(f[i-1][3], f[i][2]+r*a[i]);
	}
	cout<<f[n-1][3]<<endl;
	return 0;
}