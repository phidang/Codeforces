#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

ll n, k;

ll sum(ll x) {
	return k*(k+1)/2 - (x-1)*x/2;
}

void solve() {
	if (n==1) {
		cout<<0<<endl;
		return;
	}
	ll l = 1;
	ll r = k-1;
	n--, k--;
	ll res = -1;
	while (l<=r) {
		ll mid = (l+r)/2;
		if (sum(mid)<=n) {
			res = mid;
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	if (n-sum(res)==0) {
		cout<<k-res+1<<endl;
	}
	else if (n-sum(res)<res) {
		cout<<k-res+2<<endl;
	}
	else cout<<-1<<endl;
}

int main(){
	if (debug) openfile;
	cin>>n>>k;
	solve();
	return 0;
}