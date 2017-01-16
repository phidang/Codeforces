#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5+7;

int n, c[MAX_N], d[MAX_N];

void solve() {
	int sum = 0;
	int a = -3e7, b = 3e7;
	for (int i=0; i<n; i++) {
		if (d[i]==1) 
			a=max(a, 1900-sum);
		else b=min(b, 1899-sum);
		sum+=c[i];
	}
	if (a>b) puts("Impossible");
	else if (b==3e7) puts("Infinity");
	else cout<<b+sum<<endl;
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>c[i]>>d[i];
	}
	solve();
	return 0;
}