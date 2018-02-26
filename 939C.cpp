#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5+3;

int n, a[MAX_N], sum[MAX_N], s, f;

void prefixSum() {
	sum[1] = a[1];
	for (int i=2; i<=n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
}

void solve() {
	prefixSum();
	int maxVal = 0;
	int res = n;
	for (int i=1; i<=n-f+s; i++) {
		int val = sum[i+f-s-1] - sum[i-1];
		int tmp = (n-i+s+1)%(n/2);
		tmp = (tmp==0)?n/2:tmp;
		if (val > maxVal || (val == maxVal && tmp < res)) {
			maxVal = val;
			res = tmp;
		}
	}
	cout<<res<<endl;
}

void prepare() {
	for (int i=n+1; i<=2*n; i++) {
		a[i] = a[i-n];
	}
	n = 2*n;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	cin >> s >> f;
	prepare();
	solve();
	return 0;
}