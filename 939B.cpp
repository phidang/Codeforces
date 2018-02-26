#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5+7;
const ll oo = 1e18;

ll n, a[MAX_N], res;
int k;

int main() {
	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for (int i=0; i<k; i++) {
		cin>>a[i];
	}
	res = oo;
	int v = -1;
	for (int i=0; i<k; i++) {
		ll m = n%a[i];
		if (m < res) {
			res = m;
			v = i;
		}
	}
	cout<<v+1<<' '<<n/a[v]<<endl;
	return 0;
}