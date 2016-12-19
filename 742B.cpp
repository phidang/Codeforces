#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

const int MAX_N = 1e5+7;

int n, x, a[MAX_N], cnt[MAX_N];

void input() {
	cin>>n>>x;
	for (int i=0; i<n; i++) { 
		cin>>a[i];
		cnt[a[i]]++;
	}
}

void solve() {
	ll res = 0;
	for (int i=1; i<=1e5; i++) {
		if (cnt[i]==0) continue;
		if ((i^x)<=1e5 && (i^x)>i) {
			res += (ll)cnt[i]*cnt[(i^x)];
		}
		else if ((i^x)==i) {
			res += (ll)cnt[i]*(cnt[i]-1)/2;
		}
	}
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	input();
	solve();
	return 0;
}