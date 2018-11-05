#include <bits/stdc++.h>

using namespace std;

#define debug 01
#define openfile {freopen("input.txt","r",stdin);}

int n, k;
long long res;

void solve() {
	cin>>n>>k;
	int residual = 0;
	res=0;
	for (int i=0; i<n; i++) {
		int x;
		cin>>x;
		res+=residual/k;
		residual-=(residual/k);
		if (residual>0 && residual+x<k) {
			res++;
			residual=0;
		}
		else {
			res+=(residual + x)/k;
			residual = (residual+x)%k;	
		}
	}
	if (residual>0) res++;
	cout<<res<<endl;
}

int main() {
	if (debug) openfile;
	solve();
	return 0;
}