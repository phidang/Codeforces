#include <bits/stdc++.h>

using namespace std;

#define openfile {freopen("input.txt","r",stdin);}
#define debug 01

const int MAX_N = 510;

int n, k, sum, a[MAX_N], res[MAX_N];

int main() {
	if (debug) openfile;
	cin>>n>>k;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	res[0] = a[0];
	sum = 0;
	for (int i=1; i<n; i++) {
		res[i]=max(k-res[i-1], a[i]);
		sum += res[i]-a[i];
	}	
	cout<<sum<<endl;
	for (int i=0; i<n; i++) {
		cout<<res[i]<<" ";
	}
	return 0;
}