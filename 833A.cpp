#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a, b;

ll cuberoot(ll num) {
	ll l=0, r=1e6;
	while (l<=r) {
		ll mid=(r+l+1)/2;
		ll x = mid*mid*mid;
		if (x == num) {
			return mid;
		}
		else if (x > num) {
			r = mid-1;
		}
		else l = mid+1;
	}
	return -1;
}

bool check(ll a, ll b) {
	ll x = cuberoot(a*b);
	if (x==-1 || a%x!=0 || b%x!=0) {
		return false;
	} 
	return true;
}

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%I64d %I64d", &a, &b);
		if (check(a, b)) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	return 0;
}