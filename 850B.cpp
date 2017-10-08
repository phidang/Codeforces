#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5+7;

ll n, x, y, a[MAXN], res, cnt[4*MAXN], sum[4*MAXN];

void solve() {
	ll maxAi=0, res=0;
	for (int i=0; i<n; i++) {
		if (a[i]%2) {
			if (y<x) {
				res+=y;
			}
			else res+=x;
		}
		maxAi=max(maxAi, a[i]);
		cnt[a[i]]++;
	}
	for (int i=1; i<=2*maxAi; i++) {
		sum[i]=sum[i-1]+cnt[i]*i;
		cnt[i]+=cnt[i-1];
	}
	for (int i=3; i<=maxAi; i++) {
		ll newSum=0, j=1;
		while (i*j<=maxAi*2) {
			ll p=i*j-ceil(double(x)/y);
			if (p>i*(j-1)) {
				newSum+=(cnt[p]-cnt[i*(j-1)])*x + (i*j*(cnt[i*j]-cnt[p]) - sum[i*j] + sum[p])*y;
			}
			else {
				newSum+=(i*j*(cnt[i*j]-cnt[i*(j-1)]) - sum[i*j] + sum[i*(j-1)])*y;
			}
			j++;
		}
		res=min(res, newSum);
	}
	cout<<res<<endl;
}

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d %d %d\n", &n, &x, &y);
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}