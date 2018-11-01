#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int n, x, a[MAXN], cnt;

void solve() {
	cnt=0;
	if (n==2 && x==0) {
		puts("NO");
		return;
	}
	puts("YES");
	for (int i=1; i<n-2; i++) {
		cnt^=i;
		cout<<i<<' ';
	}
	if (n>2) {
		if ((cnt^(n-2))==x) {
			cout<<n-1<<' ';
			cnt^=(n-1);
		}
		else {
			cout<<n-2<<' ';
			cnt^=n-2;
		}
		cout<<(cnt^x|(1<<19))<<' ';
		cout<<(1<<19)<<endl;	
	}
	else {
		if (n==2) cout<<0<<' ';
		cout<<x<<endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>x;
	solve();
	return 0;
}