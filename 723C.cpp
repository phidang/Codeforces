#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r", stdin);}
#define debug 01

const int MAX_N = 2e3+7;

int n, m, a[MAX_N], cnt[MAX_N];

void input() {
	cin>>n>>m;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
}

void solve() {
	int res = 0;
	for (int i=0; i<n; i++) {
		if (a[i]<=m) {
			cnt[a[i]]++;
		}
	}
	int mmin = n/m;
	for (int i=0; i<n; i++) {
		if (a[i]>m) {
			for (int j=1; j<=m; j++) {
				if (cnt[j]<mmin) {
					a[i]=j;
					cnt[j]++;
					res++;
					break;
				}
			}
		}
		else if (cnt[a[i]]>mmin) {
			for (int j=1; j<=m; j++) {
				if (cnt[j]<mmin) {
					cnt[a[i]]--;
					a[i]=j;
					cnt[a[i]]++;
					res++;
					break;
				}
			}
		}
	}
	cout<<mmin<<' '<<res<<endl;
	for (int i=0; i<n; i++) {
		cout<<a[i]<<' ';
	}
}

int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}