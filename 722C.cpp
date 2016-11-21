#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

typedef long long ll;

const int MAX_N = 1e5;

int n, a[MAX_N], p[MAX_N], root[MAX_N];
ll msum[MAX_N];
vector<ll> vres;

void input() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	for (int i=0; i<n; i++) {
		cin>>p[i];
		p[i]--;
	}
}

void init() {
	for (int i=0; i<n; i++) {
		root[i]=-1;
	}
}

int getRoot(int x) {
	if (x<0 || x>=n || root[x]==-1) return -1;
	while (root[x]!=x) {
		x=root[x];
	}
	return x;
}

void solve() {
	init();

	ll res = 0;
	vres.push_back(res);
	for (int i=n-1; i>=0; i--) {
		int x;
		x = root[p[i]] = p[i];
		msum[p[i]] = a[p[i]];
		int y = getRoot(p[i]-1);
		int z = getRoot(p[i]+1);
		res = max(res, (ll)a[x]);
		if (y!=-1) {
			msum[y] = msum[y] + a[x];
			root[x] = y;
			res = max(res, msum[y]);
		}
		if (z!=-1) {
			msum[z] += msum[root[x]];
			root[root[x]] = z;
			res = max(res, msum[z]);
		}
		vres.push_back(res);
	}
}

void output() {
	for (int i=vres.size()-2; i>=0; i--) {
		cout<<vres[i]<<endl;
	}
}

int main() {
	if (debug) openfile;
	input();
	solve();
	output();
	return 0;
}