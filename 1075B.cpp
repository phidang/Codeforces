#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

const int MAXN=2e5+7;

int n, m, a[MAXN], b[MAXN], res[MAXN];

void solve() {
	cin>>n>>m;
	for (int i=0; i<n+m; i++) {
		cin>>a[i];
	}
	for (int i=0; i<n+m; i++) {
		cin>>b[i];
	}
	int r=0;
	int l=-1;
	while (r<n+m && b[r]==0) r++;
	for (int i=0; i<n+m; i++) {
		if (b[i]==1) {
			if (l!=-1)
				cout<<res[l]<<' ';
			l=i;
			r=l+1;
			while (r<n+m && b[r]==0) r++;
		}
		else {
			if (l!=-1 && r!=m+n) {
				if (a[i]-a[l] > a[r]-a[i]) {
					res[r]++;
				}
				else res[l]++;
			}
			else if (l==-1) res[r]++;
			else res[l]++;
		}
	}
	cout<<res[l];
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}